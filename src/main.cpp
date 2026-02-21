#include "library.h"
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout << "Library Management System Started" << endl;

    Library library;
    int choice;

    while(true)
    {
        cout << "\n------ MENU ------\n" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Update Book by ID" << endl;
        cout << "5. Delete Book by ID" << endl;
        cout << "6. Issue Book" << endl;
        cout << "7. Return Book" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        switch(choice)
        {
            case 1:
                library.addBook();
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                library.searchByTitle();
                break;

            case 4:
                library.updateBookByID();
                break;

            case 5:
                library.deleteBookByID();
                break;

            case 6:
                library.issueBookByID();
                break;

            case 7:
                library.returnBookByID();
                break;

            case 8:
                cout << "Exiting Library System..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}