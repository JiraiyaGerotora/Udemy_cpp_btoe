#include "tic-tac-toe-NxN.h"

void printArr(std::string* arr, int numCells)
{
    system("clear");
    int i, j, difflen, curlen, maxlen = (std::to_string(numCells*numCells)).length();
    //std::cout << "numCells " << numCells << std::endl;
    std::cout << std::endl;
    for (i = 0; i < numCells; i++)
    {
        for (j = 0; j < numCells; j++)
        {
            curlen = (*(arr+i*numCells+j)).length();
            difflen = maxlen - curlen;
            //std::cout << "maxlen " << maxlen << "curlen " << curlen << "\n";
            while (difflen-- > 0)
                std::cout << " ";
            std::cout << *(arr+i*numCells+j) << "    ";
        }

        std::cout << "\n\n\n";
    }
}

bool IsGameOver(std::string* arr, int numCells)
{
    // i,j -> iterate over cells starting with x/y-axis
    // k -> To start with any point and iterate towards back slash shaped diagonals
    // l -> To start with a x-axis point and move towards slash shaped diagonals (used in upper pane)
    // m,n -> To start with a x-axis point from end and moved towards slash shaped diagonals (lower pane)
    int i, j, k, l, m, n;
    for (i = 0; i < numCells; i++)
    {
        int iHorCount, iVerCount, iUBSlashDiag, iLBSlashDiag, iUSlashDiag, iLSlashDiag;
        iHorCount = iVerCount = iUBSlashDiag = iLBSlashDiag = iUSlashDiag = iLSlashDiag = 1;

        for (j=0, k=i, l=i, m=numCells-1, n=numCells-i-1; j<numCells-1; j++, k++, l--,m--,n++)
        {
            // Horizontal Lines
            //std::cout << "iHorCount = " << iHorCount << "\n";
            if (*(arr+i*numCells+j) != *(arr+i*numCells+j+1))
                iHorCount = 0;
            iHorCount++;
            //std::cout << "iHorCount = " << iHorCount << "\n";

            // Vertical Lines
            //std::cout << "iVerCount = " << iVerCount << "\n";
            if (*(arr+j*numCells+i) != *(arr+(j+1)*numCells+i))
                iVerCount = 0;
            iVerCount++;
            //std::cout << "iVerCount = " << iVerCount << "\n";

            // Back Slash shaped diagonals (Lower pane)
            //std::cout << "iLBSlashDiag = " << iLBSlashDiag << "\n";
            if (k >= numCells-1 || *(arr+k*numCells+j) != *(arr+(k+1)*numCells+j+1))
                iLBSlashDiag = 0;
            iLBSlashDiag++;
            //std::cout << "iLBSlashDiag = " << iLBSlashDiag << "\n";

            // Slash shaped diagonals (Upper pane)
            //std::cout << "iUBSlashDiag = " << iUBSlashDiag << "\n";
            if (k >= numCells-1 || *(arr+j*numCells+k) != *(arr+(j+1)*numCells+k+1))
                iUBSlashDiag = 0;
            iUBSlashDiag++;
            //std::cout << "iUBSlashDiag = " << iUBSlashDiag << "\n";

            // Slash shape diagonals (Upper pane)
            //std::cout << "iUSlashDiag = " << iUSlashDiag << "\n";
            if (l <= 0 || *(arr+l*numCells+j) != *(arr+(l-1)*numCells+(j+1)))
                iUSlashDiag = 0;
            iUSlashDiag++;
            //std::cout << "iUSlashDiag = " << iUSlashDiag << "\n";

            // Slash shaped diagonals (Lower pane)
            //std::cout << "iLSlashDiag = " << iLSlashDiag << "\n";
            if (m <= 0 || n >= numCells-1 || *(arr+m*numCells+n) != *(arr+(m-1)*numCells+n+1))
                iLSlashDiag = 0;
            iLSlashDiag++;
            //std::cout << "iLSlashDiag = " << iLSlashDiag << "\n";
        }

        if (iHorCount == numCells || iVerCount == numCells || iLBSlashDiag == numCells ||
            iUBSlashDiag == numCells || iUSlashDiag == numCells || iLSlashDiag == numCells)
        {
            return true;
        }
    }
    return false;
}

int main (int argc, char** argv)
{
    int numCells;
    std::cout << "Enter number of cells: ";
    std::cin >> numCells;
    std::string *arr = NULL;
    arr = (std::string*) malloc(numCells*numCells*sizeof(std::string));

    // Fill up the matrix with numbers and print them on screen
    for (int i = 0; i < numCells; i++)
    {
        for (int j = 0; j < numCells; j++)
        {
            *(arr+i*numCells+j) = std::to_string(i*numCells + j + 1);
        }
    }
    printArr((std::string*)arr, numCells);

    int x,y;
    static int count = 0;
    while(count < numCells*numCells)
    {
        std::cout << "Player " << (count % 2 ? "2" : "1") << "\n";

        // Take input from user in x and y coordinates
        do{ std::cout << "x: "; std::cin >> x; } while(x > numCells || x <= 0);
        do{ std::cout << "y: "; std::cin >> y; } while(y > numCells || y <= 0);

        if (*(arr+(x-1)*numCells+y-1) != "O" && *(arr+(x-1)*numCells+y-1) != "X")
        {
            *(arr+(x-1)*numCells+y-1) = count++%2 ? "O" : "X";
            printArr((std::string*)arr, numCells);
            if (IsGameOver((std::string*)arr, numCells))
            {
                std::cout << "Player " << ((count-1) % 2 ? "2" : "1") << " won\n";
                break;
            }
        }
    }

    free (arr);
    return 0;
}