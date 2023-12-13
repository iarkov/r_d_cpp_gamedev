#include "functionsHW10.h"

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;
}

bool calculateSum(const double* arr, int arrSize, double& sum) {
    if (arrSize <= 0) {
        return false;
    }
    else {
        for (int i = 0; i < arrSize; i++) {
            sum += arr[i];
        }

        return true;
    }
}

bool find(const int* arr, int size, int elem) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == elem) {
            return true;
        }
    }

    return false;
}