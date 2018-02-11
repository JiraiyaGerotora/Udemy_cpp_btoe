#ifndef USER_H
#define USER_H

#include <iostream>
#include "book.h"

class Library;
class Librarian;
class Borrower;

class User
{
    protected:
        std::string userName;
        std::string userLastName;
    public:
        User(std::string, std::string);
        ~User();
        std::string userGetName();
        std::string userGetLastName();
};

class Borrower : public User
{
    protected:
        friend class Librarian;
        int brwrMaxBookAmt;
        int brwrCurBookAmt;
        Book * brwrCurBookList;
    public:
        Borrower(std::string, std::string, int);
        ~Borrower();

        Book& brwrGetBook(int id);
        void brwrReturnBook(Library&, int);
        void brwrShowBooks();

        Borrower(const Borrower&) = delete;
        Borrower& operator=(const Borrower&) = delete;
};

class Librarian : public Borrower
{
    public:
        Librarian(std::string, std::string, int);
        ~Librarian();
        void librarianLendBook(Library&, Borrower&, int);
};

#endif
