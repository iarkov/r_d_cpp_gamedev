#include "FunctionsHW12.h"

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort(int arr[ROWS][COLUMNS], SortingDirection sd) {
    switch (sd) {
    case SortingDirection::ByRows:
        for (int r = 0; r < ROWS; r++) {
            quickSortByRows(arr, r, 0, COLUMNS - 1);
        }
        break;
    case SortingDirection::ByColumns:
        for (int c = 0; c < COLUMNS; c++) {
            quickSortByColumns(arr, c, 0, ROWS - 1);
        }
        break;
    }
}

void quickSort(int arr[], int startIdx, int endIdx) {
    if (startIdx != endIdx) {
        int pointerIdx = startIdx - 1;
        for (int i = startIdx; i <= endIdx; i++) {
            if (arr[i] <= arr[endIdx]) {
                pointerIdx += 1;

                int temp = arr[i];
                arr[i] = arr[pointerIdx];
                arr[pointerIdx] = temp;
            }
        }

        if ((pointerIdx - 1) >= startIdx) {
            quickSort(arr, startIdx, pointerIdx - 1);
        }

        if ((pointerIdx + 1) <= endIdx) {
            quickSort(arr, pointerIdx + 1, endIdx);
        }
    }
}

void quickSortByRows(int arr[ROWS][COLUMNS], int row, int startIdx, int endIdx) {
    if (startIdx != endIdx) {
        int pointerIdx = startIdx - 1;
        for (int i = startIdx; i <= endIdx; i++) {
            if (arr[row][i] <= arr[row][endIdx]) {
                pointerIdx += 1;

                int temp = arr[row][i];
                arr[row][i] = arr[row][pointerIdx];
                arr[row][pointerIdx] = temp;
            }
        }

        if ((pointerIdx - 1) >= startIdx) {
            quickSortByRows(arr, row, startIdx, pointerIdx - 1);
        }

        if ((pointerIdx + 1) <= endIdx) {
            quickSortByRows(arr, row, pointerIdx + 1, endIdx);
        }
    }
}

void quickSortByColumns(int arr[ROWS][COLUMNS], int column, int startIdx, int endIdx) {
    if (startIdx != endIdx) {
        int pointerIdx = startIdx - 1;
        for (int i = startIdx; i <= endIdx; i++) {
            if (arr[i][column] <= arr[endIdx][column]) {
                pointerIdx += 1;

                int temp = arr[i][column];
                arr[i][column] = arr[pointerIdx][column];
                arr[pointerIdx][column] = temp;
            }
        }

        if ((pointerIdx - 1) >= startIdx) {
            quickSortByColumns(arr, column, startIdx, pointerIdx - 1);
        }

        if ((pointerIdx + 1) <= endIdx) {
            quickSortByColumns(arr, column, pointerIdx + 1, endIdx);
        }
    }
}
