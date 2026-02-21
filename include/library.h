#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;

public:
    Library();

    void addBook();
    void displayBooks() const;
    void searchByTitle() const;
    void updateBookByID();
    void deleteBookByID();
    void issueBookByID();
    void returnBookByID();
};

#endif