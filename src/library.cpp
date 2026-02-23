#include "library.h"
#include <iostream>
#include <limits>

// Forward declaration from Book.cpp
void rewriteFile(const std::vector<Book> &library);

Library::Library()
{
    Book::loadFromFile(books);
}

void Library::addBook()
{
    Book book;
    book.addBook();

    if(isDuplicateID(book.getID()))
    {
        std::cout << "Error: Book with this ID already exists" <<std::endl;
        return;
    }
    books.push_back(book);
    book.saveToFile();

    std::cout << "Book added successfully!" << std::endl;
}

void Library::displayBooks() const
{
    if(books.empty())
    {
        std::cout << "No books in library." << std::endl;
        return;
    }

    for(const auto &book : books)
    {
        book.displayBook();
    }
}

void Library::searchByTitle() const
{
    if(books.empty())
    {
        std::cout << "No books available to search." << std::endl;
        return;
    }

    std::string title;
    std::cout << "Enter Book Title to search: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, title);

    bool found = false;

    for(const auto &book : books)
    {
        if(book.getTitle() == title)
        {
            std::cout << "\n--- Book Found ---\n";
            book.displayBook();
            found = true;
            break;
        }
    }

    if(!found)
    {
        std::cout << "Book not found in library." << std::endl;
    }
}

void Library::updateBookByID()
{
    if(books.empty())
    {
        std::cout << "No books available to update." << std::endl;
        return;
    }

    int id;
    std::cout << "Enter Book ID to update: ";
    std::cin >> id;

    bool found = false;

    for(auto &book : books)
    {
        if(book.getID() == id)
        {
            book.updateBook();
            rewriteFile(books);
            std::cout << "Book updated successfully!" << std::endl;
            found = true;
            break;
        }
    }

    if(!found)
    {
        std::cout << "Book with given ID not found." << std::endl;
    }
}

void Library::deleteBookByID()
{
    if(books.empty())
    {
        std::cout << "No books available to delete." << std::endl;
        return;
    }

    int id;
    std::cout << "Enter Book ID to delete: ";
    std::cin >> id;

    for(size_t i = 0; i < books.size(); i++)
    {
        if(books[i].getID() == id)
        {
            books.erase(books.begin() + i);
            rewriteFile(books);
            std::cout << "Book deleted successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Book with given ID not found." << std::endl;
}

void Library::issueBookByID()
{
    if(books.empty())
    {
        std::cout << "No books available to issue." << std::endl;
        return;
    }

    int id;
    std::cout << "Enter Book ID to issue: ";
    std::cin >> id;

    for(auto &book : books)
    {
        if(book.getID() == id)
        {
            book.issueBook();
            rewriteFile(books);
            return;
        }
    }

    std::cout << "Book with given ID not found." << std::endl;
}

void Library::returnBookByID()
{
    if(books.empty())
    {
        std::cout << "No books available." << std::endl;
        return;
    }

    int id;
    std::cout << "Enter Book ID to return: ";
    std::cin >> id;

    for(auto &book : books)
    {
        if(book.getID() == id)
        {
            book.returnBook();
            rewriteFile(books);
            return;
        }
    }

    std::cout << "Book with given ID not found." << std::endl;
}

bool Library::isDuplicateID(int id) const
{
    for(size_t i=0;i<books.size();i++)
    {
        if(books[i].getID()==id)
        {
            return true;
        }
    }
    return false;
}