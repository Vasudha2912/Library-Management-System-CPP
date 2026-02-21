#include "book.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout<< "Library Management Started" <<endl;

    vector<Book> library;
    int choice;

    while(true)
    {
        cout << "\n------MENU------\n" <<endl;
        cout << "1. Add Book " << endl;
        cout << "2. Display Books " << endl;
        cout << "3. Search the book by Title " <<endl;
        cout << "4. Exit " <<endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if(choice==1)
        {
            Book book;
            book.addBook();
            library.push_back(book);

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
                cin.ignore();
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
        else if(choice==4)
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