#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book{
    private:
        int bookID;
        std::string bookTitle;
        std::string bookAuthor;

    public:
        void addBook();
        void displayBook();
        std::string getTitle() const;//used const because fucntion doesnot modify the object
        int getID() const;
        std::string getAuthor() const;
        void saveToFile();
        static void loadFromFile(std::vector<Book> &library);//used static because it will call before any obejct exists
        void updateBook();
};

#endif