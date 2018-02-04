#include <iostream>

int main()
{
    int a;
    int * b = new int;
    int *p = &a;
    *p = 5;
    *b = 9;
    std::cout << "The value of the statically allocated variable: " << a << 
        " and the address: " << &a << "\n";
    std::cout << "The value of the dynamically allocated variable: " << *b << 
        " and the address: " << b << "\n";

    delete b;
    b = NULL;

    return 0;
}