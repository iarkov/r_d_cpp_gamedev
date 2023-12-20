#include <iostream>
#include <iomanip>
#include "Functions HW11.h"

int main()
{
    // ---------------- TASK 1 ----------------
    std::cout << "---------------- TASK 1 ----------------" << std::endl << std::endl;

    int arr2D[ROWS][COLUMNS] = { {1,2,4},{2,3,4},{1,1,1} };
    bool found = find(arr2D, 3);

    if (found) {
        std::cout << "Number is found in the array!";
    }
    else {
        std::cout << "Number is not found in the array :(";
    }

    std::cout << std::endl << std::endl;

    // ---------------- TASK 2 ----------------
    std::cout << "---------------- TASK 2 ----------------" << std::endl << std::endl;

    int arrAscending[]{ 1,2,3,4 };
    int arrDescending[]{ 4,3,2,1 };
    int arrDisordered[]{ 4,2,1,3 };


    std::cout << std::boolalpha << "arrAscending is sorted in ascending order: ";
    std::cout << isSorted(arrAscending, sizeof(arrAscending) / sizeof(int), static_cast<SortingDirection>(0)) << std::endl;

    std::cout << "arrAscending is sorted in descending order: ";
    std::cout << isSorted(arrAscending, sizeof(arrAscending) / sizeof(int), static_cast<SortingDirection>(1)) << std::endl;

    std::cout << "arrDescending is sorted in ascending order: ";
    std::cout << isSorted(arrDescending, sizeof(arrDescending) / sizeof(int), static_cast<SortingDirection>(0)) << std::endl;

    std::cout << "arrDescending is sorted in descending order: ";
    std::cout << isSorted(arrDescending, sizeof(arrDescending) / sizeof(int), static_cast<SortingDirection>(1)) << std::endl;

    std::cout << "arrDisordered is sorted in ascending order: ";
    std::cout << isSorted(arrDisordered, sizeof(arrDisordered) / sizeof(int), static_cast<SortingDirection>(0)) << std::endl;

    std::cout << "arrDisordered is sorted in descending order: ";
    std::cout << isSorted(arrDisordered, sizeof(arrDisordered) / sizeof(int), static_cast<SortingDirection>(1)) << std::endl;

    std::cout << std::endl << std::endl;

    // ---------------- TASK 3 ----------------
    std::cout << "---------------- TASK 3 ----------------" << std::endl << std::endl;

    int arrToFlatten[ROWS][COLUMNS]{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };

    std::cout << "printFlat1: "; 
    printFlat1(arrToFlatten);
    std::cout << std::endl;

    std::cout << "printFlat2: ";
    printFlat2(arrToFlatten);
    std::cout << std::endl;
}
