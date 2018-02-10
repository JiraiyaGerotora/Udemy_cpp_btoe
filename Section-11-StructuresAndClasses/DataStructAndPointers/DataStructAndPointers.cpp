#include <string>
#include <iostream>
#include "library.h"
#include "book.h"
#include "user.h"


int main (int argc, char * argv[])
{
    const Book book1("To kill a Mockingbird", "Harper Lee", 1960);
    const Book book2("When Breath Becomes Air", "Paul Kalanithi", 2016);
    const Book book3("The Remains of the Day", "Kazuo Ishiguro", 1989);
    const Book book4 = book3;
    const Book book5 = book3;
    const Book book6 = book3;

    Library library(5);
    Librarian librarian("Jeffrey", "Archer", 5);
    Borrower borrower("Adams", "Lara", 5);

    library.libraryAddBook(book1);
    library.libraryAddBook(book2);
    library.libraryAddBook(book3);
    library.libraryAddBook(book4);
    library.libraryAddBook(book5);
    library.libraryAddBook(book6);

    int index;
    char choice;
    while(true)
    {
        library.libraryShowBooks();
        borrower.brwrShowBooks();
        std::cout << "Would you like to Borrow - B/b or Return - R/r: ";
        std::cin >> choice;
        switch(choice)
        {
            case 'b':
            case 'B':
            {
                std::cout << "Which book would you like to rent, POSITION IN LIBRARY: ";
                std::cin >> index;
                librarian.librarianLendBook(library, borrower, index);
                break;
            }
            case 'r':
            case 'R':
            {
                std::cout << "Which book would you like to return, POSITION IN USER: ";
                std::cin >> index;
                borrower.brwrReturnBook(library, index);
                break;
            }
            default:
                std::cout << "Wrong choice!\n";
        }
        system("clear");
    }
    return 0;
}