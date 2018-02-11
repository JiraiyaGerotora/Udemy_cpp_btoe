#include "library.h"

Library::Library(int libraryMaxBookAmt)
{
    libraryCurBookAmt = 0;
    this->libraryMaxBookAmt = libraryMaxBookAmt;
    this->libraryBookList = new Book[libraryMaxBookAmt];
}

Library::~Library()
{
    delete [] libraryBookList;
}

void Library::libraryAddBook (const Book & book)
{
    if (libraryCurBookAmt < libraryMaxBookAmt)
        this->libraryBookList[this->libraryCurBookAmt++] = book;
}

Book Library::libraryGetBook (int index)
{
    if ( index >= libraryMaxBookAmt )
        index = 0;
    return libraryBookList[index];
}

void Library::libraryShowBooks()
{
    for (int i = 0; i < libraryCurBookAmt; i++)
    {
        //libraryGetBook(i) is same as libraryBookList[i]
        //std::cout << "ID: " << libraryGetBook(i).bookGetID() << "; ";
        std::cout << "ID: " << libraryGetBook(i).bookGetID() << "; ";
        std::cout << "Title: " << libraryGetBook(i).bookGetTitle() << "; ";
        std::cout << "Author: " << libraryGetBook(i).bookGetAuthor() << "; ";
        std::cout << "Year: " << libraryGetBook(i).bookGetPublicationYr() << "\n";
    }
}
