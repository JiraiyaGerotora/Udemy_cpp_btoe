#include <iostream>

void setValue( int &a )
{
    std::cin >> a;
}

int main()
{
    int x;
    setValue(x);
    std::cout << x << "\n";
    return 0;
}