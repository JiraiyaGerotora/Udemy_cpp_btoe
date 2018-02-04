#include <iostream>

void CheckIfTheSame( int& a, int& b)
{
    if (a == b && &a == &b)
        std::cout << "Values and addresses same\n";

    if (a == b && &a != &b)
        std::cout << "Values same, addresses different\n";

    if (a != b && &a != &b)
        std::cout << "Values and addresses different\n";
}

int main()
{
    int a=10, b=20; 
    int c = a;
    int & d = a;
    CheckIfTheSame( a, b);
    CheckIfTheSame( a, c);
    CheckIfTheSame( a, d);
    CheckIfTheSame( b, c);
    CheckIfTheSame( b, d);
    CheckIfTheSame( c, d);

    return 0;
}