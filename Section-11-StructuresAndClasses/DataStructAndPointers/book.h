#ifndef BOOK_H
#define BOOK_H

#include <iostream>

class Book
{
    private:
        std::string bookTitle;
        std::string bookAuthor;
        int bookPublicationYear;
        long bookID;
        static int noOfBooks;
    public:
        Book(std::string, std::string, int);
        Book (const Book &);
        Book();
        ~Book();

        std::string bookGetTitle() const;
        std::string bookGetAuthor() const;
        int bookGetPublicationYr() const;
        long bookGetID() const;
};

#endif