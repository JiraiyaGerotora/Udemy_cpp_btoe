#include <iostream>

// All functions declaration
int * createArray(int sizeOfArr);
void fillArrayWithValues( int * arr, int sizeOfArr);
void printArr(int * arr, int sizeOfArr);
void swapTwoValues( int& val1, int& val2);
void bubbleSort(int *arr, int sizeOfArr, int order);
void selectionSort(int * arr, int sizeOfArr, int order);


int main(int argc, char * argv[])
{
    int sizeOfArr;
    int order;
    char sortType;
    std::cout << "Input the size of the array to sort\n";
    std::cin >> sizeOfArr;
    int * arr = createArray(sizeOfArr);
    fillArrayWithValues(arr, sizeOfArr);
    printArr(arr, sizeOfArr);
    std::cout << "Sort Ascending - 1, Descending - 2: ";
    std::cin >> order;
    std::cout << "Bubble Sort - B or b, Selection Sort - S or s: ";
    std::cin >> sortType;
    if (sortType == 'B' || sortType == 'b')
        bubbleSort(arr, sizeOfArr, order);
    else if (sortType == 'S' || sortType == 's')
        selectionSort(arr, sizeOfArr, order);
    printArr(arr, sizeOfArr);

    delete[] arr;
    return 0;
}

// Dynamically allocates array of spaces of size int
int * createArray(int sizeOfArr)
{
    int * arr = new int[sizeOfArr];
    return arr;
}

// Fills the array with random values
void fillArrayWithValues( int * arr, int sizeOfArr)
{
    srand(time(NULL));
    for (int i = 0; i < sizeOfArr; i++)
    {
        arr[i] = rand()%1500;
        //std::cout << "Enter " << i+1 << " element: ";
        //std:: cin >> arr[i];
    }
}

// Outputs the array values on screen
void printArr(int * arr, int sizeOfArr)
{
    system("clear");
    for (int i = 0; i < sizeOfArr; i++)
        std::cout << "Array[" << i << "]=" << arr[i] << "\n";
}

// Swaps two variable values
void swapTwoValues( int& val1, int& val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

// Sorts an integer array using bubble sort algorithm
void bubbleSort(int *arr, int sizeOfArr, int order = 1)
{
    for (int i = 0; i < sizeOfArr-1; i++)
    {
        for (int j = i+1; j < sizeOfArr; j++)
        {
            if (order == 2)
            {
                if (arr[i] < arr[j])
                    swapTwoValues(arr[i], arr[j]);
            }
            else
            {
                if (arr[i] > arr[j])
                    swapTwoValues(arr[i], arr[j]);
            }
        }
    }
}

// Sorts an integer array using bubble sort algorithm
void selectionSort(int * arr, int sizeOfArr, int order = 1)
{
    int minOrMaxIndex, unsortIndex = 0;
    while (unsortIndex < sizeOfArr-1)
    {
        minOrMaxIndex = unsortIndex;
        for (int i = unsortIndex+1; i < sizeOfArr; i++)
        {
            if (order == 2)
            {
                if (arr[i] > arr[minOrMaxIndex])
                {
                    minOrMaxIndex = i;
                }
            }
            else
            {
                if (arr[i] < arr[minOrMaxIndex])
                {
                    minOrMaxIndex = i;
                }
            }
        }
        swapTwoValues(arr[unsortIndex++], arr[minOrMaxIndex]);
    }
}