#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book{
    private:
        int bookID;
        std::string bookTitle;
        std::string bookAuthor;

    public:
        void addBook();
        void displayBook();
};

#endif