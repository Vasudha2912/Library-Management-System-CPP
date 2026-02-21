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
        cout <<"3. Exit " <<endl;

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

        else if(choice==3)
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