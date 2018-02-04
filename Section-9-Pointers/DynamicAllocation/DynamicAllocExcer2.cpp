#include <iostream>

int main()
{
    int sizeOfDynamicArr;
    std::cout << "User Inputted\n";
    std::cout << "Input the size of the dynamic array you want to create: ";
    std::cin >> sizeOfDynamicArr;
    int * pDynamicArr = new int[sizeOfDynamicArr];
    for (int i=0; i < sizeOfDynamicArr; i++)
    {
        std::cout << "Input " << i+1 << " number: ";
        std::cin >> *(pDynamicArr+i);
    }
    for (int i=0; i < sizeOfDynamicArr; i++)
    {
        std::cout << "Number " << i+1 << ": " << *(pDynamicArr + i) << "\n";;
    }
    return 0;
}