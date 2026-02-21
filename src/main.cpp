#include "book.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void rewriteFile(const std::vector<Book> &library); //forward declaration
int main()
{
    cout<< "Library Management Started" <<endl;

    vector<Book> library;
    Book::loadFromFile(library);
    int choice;

    while(true)
    {
        cout << "\n------MENU------\n" <<endl;
        cout << "1. Add Book " << endl;
        cout << "2. Display Books " << endl;
        cout << "3. Search the book by Title " <<endl;
        cout << "4. Update the book by ID" << endl;
        cout << "5. Delete the book by Id "<< endl;
        cout << "6. Exit " <<endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if(choice==1)
        {
            Book book;
            book.addBook();
            library.push_back(book);
            book.saveToFile();

            cout << "Book is Added" << endl;
        }
        else if(choice==2)
        {
            if(library.empty())
            {
                cout << "Sorry,No book in Library"<<endl;
                cout << "Come Later" <<endl;
            }
            else{
                for(size_t i =0;i<library.size();i++)
                {
                    library[i].displayBook();
                }
            }
        }

        else if(choice == 3)
        {
            if(library.empty())
            {
                cout << "Sorry,No book in Library to search"<<endl;
                cout << "Come Later" <<endl;
            }
            else{
                string title;
                bool found= false;

                cout << "Please enter the book title: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,title);

                for(size_t i=0;i<library.size();i++)
                {
                    if(library[i].getTitle()==title)
                    {
                        cout << "\n---Book found---\n";
                        library[i].displayBook();
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "No book found in the library" <<endl;
                }
            }
        }

        else if(choice == 4)
        {
            if(library.empty())
            {
                cout << "Sorry,No book in Library to update"<<endl;
                cout << "Come Later" <<endl;
            }

            else
            {
                int updateId;
                bool found=false;

                cout << "Enter the Book Id to update: "<<endl;
                cin>>updateId;
                for(size_t i =0;i<library.size();i++)
                {
                    if(library[i].getID()==updateId)
                    {
                        cout << "Updating the Book Details......" <<endl;
                        library[i].updateBook();
                        rewriteFile(library);
                        cout<< "Updated the Book Details Successfully!"<<endl;
                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    cout << "Book with givenID not found" <<endl;
                }
            }
        }

        else if(choice == 5)
        {
            if(library.empty())
            {
                cout << "Sorry,No book in Library to delete"<<endl;
                cout << "Come Later" <<endl;
            }

            else{
                int deleteId;
                bool found = false;

                cout << "Please enter the book Id to delete: " <<endl;
                cin>> deleteId;

                for(size_t i=0;i<library.size();i++)
                {
                    if(library[i].getID()==deleteId)
                    {
                        library.erase(library.begin()+i);
                        rewriteFile(library);
                        cout << "Book deleted successfully!" <<endl;
                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    cout << "Book with givenID not found" <<endl;
                }
            }
        }
        else if(choice==6)
        {
            cout << "Exiting Library System........" <<endl;
            break;
        }

        else{
            cout << "Invalid Choice...Please try again" <<endl;
        }
    }
    return 0;
}