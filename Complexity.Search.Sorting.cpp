#include <iostream>
#include "FunctionsHW12.h"

int main()
{
    // ---------------------- TASK 1 ----------------------
    std::cout << "---------------------- TASK 1 ----------------------" << std::endl << std::endl;


    int kek[]{ 4,1,2,3,5 };

    bubbleSort(kek, sizeof(kek) / sizeof(int));

    std::cout << "Sorted one-dimensional array with bubleSort: " << std::endl;
    for (int i = 0; i < sizeof(kek) / sizeof(int); i++) {
        std::cout << kek[i] << " ";
    }

    std::cout << std::endl << std::endl;

    // ---------------------- TASK 2 ----------------------
    std::cout << "---------------------- TASK 2 ----------------------" << std::endl << std::endl;

    std::cout << "Sorted one - dimensional array with quickSort :" << std::endl;
    int array[5]{ 5,3,2,4,1 };
    quickSort(array, 0, sizeof(array) / sizeof(int) - 1); // This was just for practice

    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;

    int arr_2d_byRows[ROWS][COLUMNS]{ {3,2,1,4,5}, {2,3,5,1,4}, {1,4,5,2,3}, {4,1,3,5,2}, {5,4,1,3,2} };
    sort(arr_2d_byRows, SortingDirection::ByRows);

    std::cout << "Sorted two-dimensional array by rows with quickSort:" << std::endl;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLUMNS; c++) {
            std::cout << arr_2d_byRows[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;

    int arr_2d_byColumns[ROWS][COLUMNS] = {
      {3, 2, 3, 1, 5},
      {1, 4, 5, 2, 3},
      {2, 5, 1, 4, 4},
      {4, 1, 4, 5, 2},
      {5, 3, 2, 3, 1}
    };

    sort(arr_2d_byColumns, SortingDirection::ByColumns);

    std::cout << "Sorted two-dimensional array by columns with quickSort:" << std::endl;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLUMNS; c++) {
            std::cout << arr_2d_byColumns[r][c] << " ";
        }
        std::cout << std::endl;
    }
}


