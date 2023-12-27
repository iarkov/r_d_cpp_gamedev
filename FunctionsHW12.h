#pragma once

const int ROWS = 5;
const int COLUMNS = 5;

enum class SortingDirection { ByRows, ByColumns };

void bubbleSort(int arr[], int size);

void sort(int arr[ROWS][COLUMNS], SortingDirection);
void quickSort(int arr[], int startIdx, int endIdx);
void quickSortByRows(int arr[ROWS][COLUMNS], int row, int startIdx, int endIdx);
void quickSortByColumns(int arr[ROWS][COLUMNS], int column, int startIdx, int endIdx);