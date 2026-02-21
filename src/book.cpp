#include "book.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

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

bool Book::getIssuedStatus() const
{
    return isIssued;
}

string Book::getIssuedTo() const{
    return issuedTo;
}

string Book::getIssuedDate() const{
    return issuedDate;
}

void Book::addBook()
{
    cout<<"Enter Book Id: "<<endl;
    cin>>bookID;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"Enter Book Title: "<<endl;
    getline(cin,bookTitle);

    cout<<"Enter Book Author: "<<endl;
    getline(cin,bookAuthor);

    isIssued=false;
    issuedTo ="";
    issuedDate = "";
}

void Book::displayBook() const
{
    cout<< "\n---------------Book Details---------------\n";
    cout<<  "Book ID     : " << bookID << endl;
    cout << "Book Title  : " << bookTitle << endl;
    cout << "Book Author : " << bookAuthor << endl;

    if(isIssued)
    {
        cout<< "Status : Issued" <<endl;
        cout << "Issued To : "<<issuedTo <<endl;
        cout << "Issued Date: "<<issuedDate <<endl;
    }
    else{
        cout << "Status : Available"<<endl;
    }
}

void Book::saveToFile()
{
    ofstream outFile("books.txt",ios::app);

    if(outFile.is_open())
    {
        outFile << bookID <<endl;
        outFile << bookTitle <<endl;
        outFile << bookAuthor << endl;
        outFile << isIssued <<endl;
        outFile << issuedTo << endl;
        outFile << issuedDate <<endl;
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
        inFile >> temp.isIssued;
        inFile.ignore();
        getline(inFile, temp.issuedTo);
        getline(inFile, temp.issuedDate);

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
        outFile << library[i].getIssuedStatus() <<endl;
        outFile << library[i].getIssuedTo() <<endl;
        outFile << library[i].getIssuedDate() <<endl;
    }

    outFile.close();
}

void Book::updateBook()
{
    cout << "Enter new Book Title: " <<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,bookTitle);

    cout << "Enter new Book Author: " << endl;
    getline(cin, bookAuthor);
}

void Book::issueBook()
{
    if(isIssued)
    {
        cout << "This book is already issued to " << issuedTo << " on " << issuedDate;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Student Name: "<<endl;
    getline(cin, issuedTo);

    cout<< "Enter the date(DD-MM-YYYY): "<<endl;
    getline(cin,issuedDate);

    isIssued=true;
    cout<<"Book Issued Successfully!";
}

void Book::returnBook()
{
    if(!isIssued)
    {
        cout << "This book is not issued to anyone" <<endl;
        return; 
    }

    cout << "Book returned successfully from "<<issuedTo<<endl;

    isIssued = false;
    issuedTo = "";
    issuedDate = "";
}
