#include <string>
#include <iostream>

struct book
{
    std::string title;
    std::string author;
    int year;
};

void setBook (book * bk)
{
    std::cout << "Enter book title: "; //Shouldn't use cin >> (*bk).title; it won't take spaces
    std::getline(std::cin, (*bk).title); // bk->title is same as (*bk).title; bk being a pointer
    std::cout << "Enter book author: ";
    std::getline(std::cin, (*bk).author);
    std::cout << "Enter book published year: ";
    std::cin >> (*bk).year;
}

void showBook (book * bk)
{
    std::cout << "Book title: " << bk->title << "\n";
    std::cout << "Book author: " << bk->author << "\n";
    std::cout << "Book published year: " << bk->year << "\n";
}

int main (int argc, char * argv[])
{
    book bk;
    setBook(&bk);
    showBook(&bk);
}