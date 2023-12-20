#include "Functions HW11.h"
#include <iostream>

// Function for Task 1
bool find(int arr_2d[ROWS][COLUMNS], int toFind) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (toFind == arr_2d[i][j]) {
                return true;
            }
        }
    }

    return false;
}

// Function for Task 2
bool isSorted(const int* arr, int size, SortingDirection direction) {
    int i = 1;
    int extremElenent = arr[0];

    switch (direction)
    {
    case SortingDirection::ASCENDING:
        while (i < size) {
            if (arr[i] >= extremElenent) {
                extremElenent = arr[i];
            }
            else {
                return false;
            }
            i++;
        }
        break;
    case SortingDirection::DESCENDING:
        while (i < size) {
            if (arr[i] <= extremElenent) {
                extremElenent = arr[i];
            }
            else {
                return false;
            }
            i++;
        }
        break;
    }

    return true;
}

// Function for Task 3
void printFlat1(int arr_2d[ROWS][COLUMNS]) {
    for (int j = 0; j < COLUMNS; j++) {
        for (int i = 0; i < ROWS; i++) {
            std::cout << arr_2d[i][COLUMNS - 1 - j] << " ";
        }
    }
}

// Function for Task 3
void printFlat2(int arr_2d[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        if (!(i % 2)) {
            for (int j = 0; j < COLUMNS; j++) {
                std::cout << arr_2d[ROWS - 1 - i][j] << " ";
            }
        }
        else {
            for (int j = 0; j < COLUMNS; j++) {
                std::cout << arr_2d[ROWS - 1 - i][COLUMNS - 1 - j] << " ";
            }
        }
    }
}