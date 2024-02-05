#pragma once

const unsigned int ROWS = 4;
const unsigned int COLUMNS = 4;

enum class SortingDirection {
    ASCENDING = 0,
    DESCENDING = 1
};

// Function for Task 1
bool find(int arr_2d[ROWS][COLUMNS], int toFind);

// Function for Task 2
bool isSorted(const int* arr, int size, SortingDirection direction);

// Functions for Task 3
void printFlat1(int arr_2d[ROWS][COLUMNS]);
void printFlat2(int arr_2d[ROWS][COLUMNS]);