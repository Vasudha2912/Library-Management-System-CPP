#include "book.h"
#include <iostream>
using namespace std;

void Book::addBook()
{
    cout<<"Enter Book Id: "<<endl;
    cin>>bookID;

    cin.ignore();

    cout<<"Enter Book Title: "<<endl;
    getline(cin,bookTitle);

    cout<<"Enter Book Author: "<<endl;
    getline(cin,bookAuthor);
}