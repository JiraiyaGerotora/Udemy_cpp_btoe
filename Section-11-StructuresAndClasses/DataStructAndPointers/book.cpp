#include "book.h"
#include <cstdlib>
#include <ctime>

int Book::noOfBooks = 0;

Book::Book(std::string bookTitle, std::string bookAuthor, int bookPublicationYear)
{
    //std::cout << "Book constructor with params is called" << std::endl;
    static bool seeded = false;
    if (seeded == false)
    {
        srand(time(NULL));
        seeded = true;
    }
    this->bookTitle = bookTitle;
    this->bookAuthor = bookAuthor;
    this->bookPublicationYear = bookPublicationYear;
    this->bookID = 1000000000 + rand() % 9000000000;
    Book::noOfBooks++;
}

Book::Book (const Book & book)
{
    this->bookTitle = book.bookGetTitle();
    this->bookAuthor = book.bookGetAuthor();
    this->bookPublicationYear = book.bookGetPublicationYr();
    this->bookID = book.bookGetID();
    //std::cout << "Copy constructor is called" << std::endl;
}

Book::Book()
{
    //std::cout << "Book constructor is called" << std::endl;
}

Book::~Book()
{
    //std::cout << "Book destructor is called" << std::endl;
}

std::string Book::bookGetTitle() const
{
    return this->bookTitle;
}

std::string Book::bookGetAuthor() const
{
    return this->bookAuthor;
}

int Book::bookGetPublicationYr() const
{
    return this->bookPublicationYear;
}

long Book::bookGetID() const
{
    return this->bookID;
}
