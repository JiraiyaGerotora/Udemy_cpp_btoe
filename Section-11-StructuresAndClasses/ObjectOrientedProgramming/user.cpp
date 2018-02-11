#include "user.h"
#include "library.h"
// Methods of User class
User::User (std::string userName, std::string userLastName)
{
    this->userName = userName;
    this->userLastName = userLastName;
}

User::~User()
{
}

std::string User::userGetName()
{
    return this->userName;
}

std::string User::userGetLastName()
{
    return this->userLastName;
}

//Methods of Borrower class
Borrower::Borrower(std::string userName, std::string userLastName, int brwrMaxBookAmt) : User(userName, userLastName)
{
    this->brwrMaxBookAmt = brwrMaxBookAmt;
    this->brwrCurBookAmt = 0;
    this->brwrCurBookList = new Book[brwrMaxBookAmt];
}

Borrower::~Borrower()
{
}

Book& Borrower::brwrGetBook(int id)
{
    if (id >= brwrCurBookAmt)
    {
        id = 0;
    }
    return brwrCurBookList[id];
}

void Borrower::brwrReturnBook(Library& libraryToReturnTo, int index)
{
    if (index < this->brwrCurBookAmt && index >= 0)
    {
        libraryToReturnTo.libraryAddBook(this->brwrCurBookList[index]);
        for (int i = index; i < this->brwrCurBookAmt; i++)
        {
            this->brwrCurBookList[i] = this->brwrCurBookList[i+1];
        }
        this->brwrCurBookAmt--;
    }
}

void Borrower::brwrShowBooks()
{
    std::cout << this->userGetName() << " " << this->userGetLastName() << "\n";
    for (int i = 0; i < brwrCurBookAmt; i++)
    {
        std::cout << brwrCurBookList[i].bookGetID() << " ";
        std::cout << brwrCurBookList[i].bookGetTitle() << " ";
        std::cout << brwrCurBookList[i].bookGetAuthor() << " ";
        std::cout << brwrCurBookList[i].bookGetPublicationYr() << "\n";
    }
}

// Methods of Librarian
Librarian::Librarian(std::string userName, std::string userLastName, int brwrMaxBookAmt) :
            Borrower(userName, userLastName, brwrMaxBookAmt)
{

}

Librarian::~Librarian()
{
}

void Librarian::librarianLendBook(Library& library, Borrower& borrower, int index)
{
    if (index < library.libraryCurBookAmt && index >= 0)
    {
        if (borrower.brwrCurBookAmt < borrower.brwrMaxBookAmt - 1)
        {
            borrower.brwrCurBookList[borrower.brwrCurBookAmt] = library.libraryBookList[index];
            for (int i = index; i < library.libraryCurBookAmt-1; i++)
            {
                library.libraryBookList[i] = library.libraryBookList[i+1];
            }
            library.libraryCurBookAmt--;
            borrower.brwrCurBookAmt++;
        }
    }
}
