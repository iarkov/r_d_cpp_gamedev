#include <iostream>

bool binarySearch(int arr[], int size, int x)
{
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        const int m = l + (r - l) / 2;

        if (arr[m] == x)
            return true;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return false;
}

// Big-O Time complexity: O(R * log(C))
// Space complexity: 4*R*C + 4 (int ROWS) + 4 (int COLUMNS) + 4 (int toFind) + 4 (int i) + 4 (int l) + 4 (int r) + 4 (int m) + 4 (int size) + 4 (int x) = 4*R*C + 36
// where C = COLUMNS and R = ROWS
int main()
{
    const int ROWS = 20;
    const int COLUMNS = 30;
    int arr[ROWS][COLUMNS] = {};
    const int toFind = 0;

    //...
    //Code to setup array and value to find 
    //in one way or another
    //..

    for (int i = 0; i < ROWS; i++)
    {
        if (binarySearch(arr[i], COLUMNS, toFind))
        {
            std::cout << "FOUND";
            break;
        }
    }
}