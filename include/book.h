#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book {
private:
    int bookID;
    std::string bookTitle;
    std::string bookAuthor;
    bool isIssued;
    std::string issuedTo;
    std::string issuedDate;

public:
    void addBook();
    void displayBook() const; //used const because fucntion doesnot modify the object

    std::string getTitle() const;
    int getID() const;
    std::string getAuthor() const;
    bool getIssuedStatus() const;
    std::string getIssuedTo() const;
    std::string getIssuedDate() const;

    void updateBook();
    void issueBook();
    void returnBook();

    void saveToFile();
    static void loadFromFile(std::vector<Book> &library);//used static because it will call before any obejct exists
};

#endif