#include "book.h"
#include <iostream>
#include <fstream>
#include <vector>
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

void Book::displayBook()
{
    cout<< "\n---------------Book Details---------------\n";
    cout<<  "Book ID     : " << bookID << endl;
    cout << "Book Title  : " << bookTitle << endl;
    cout << "Book Author : " << bookAuthor << endl;
}

string Book::getTitle() const
{
    return bookTitle;
}

int Book::getID() const{
    return bookID;
}

string Book::getAuthor() const{
    return bookAuthor;
}

void Book::saveToFile()
{
    ofstream outFile("books.txt",ios::app);

    if(outFile.is_open())
    {
        outFile << bookID <<endl;
        outFile << bookTitle <<endl;
        outFile << bookAuthor << endl;
        outFile.close();
    }
}

void Book::loadFromFile(vector<Book> &library)
{
    ifstream inFile("books.txt");

    if(!inFile.is_open())
    {
        return; //File doesnt exist
    }

    while(true)
    {
        Book temp;

        //try to read bookid
        if(!(inFile>>temp.bookID))
        {
            break;
        }

        inFile.ignore();// remove leftover newline
        getline(inFile, temp.bookTitle);
        getline(inFile, temp.bookAuthor);

        library.push_back(temp);
    }
    inFile.close();
}

void rewriteFile(const std::vector<Book> &library)
{
    ofstream outFile("books.txt",ios::trunc); //ios::trunc erase old data and write fresh data

    for(size_t i =0;i<library.size();i++)
    {
        outFile << library[i].getID() <<endl;
        outFile << library[i].getTitle() <<endl;
        outFile << library[i].getAuthor() <<endl;
    }

    outFile.close();
}

void Book::updateBook()
{
    cout << "Enter new Book Title: " <<endl;
    cin.ignore();
    getline(cin,bookTitle);

    cout << "Enter new Book Author: " << endl;
    getline(cin, bookAuthor);
}
