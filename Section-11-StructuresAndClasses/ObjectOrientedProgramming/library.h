#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "user.h"

class Borrower;
class Librarian;

class Library
{
    private:
        int libraryCurBookAmt;
        int libraryMaxBookAmt;
        Book * libraryBookList;
    public:
        Library(int);
        ~Library();

        void libraryAddBook(const Book &);
        Book libraryGetBook(int);
        void libraryShowBooks();

        friend void Librarian::librarianLendBook(Library&, Borrower&, int);
};

#endif