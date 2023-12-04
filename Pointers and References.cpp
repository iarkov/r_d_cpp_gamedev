#include <iostream>

void swap(int& a, int& b);

void swap(int* a, int* b);

bool calculateSum(const double* arr, int arrSize, double& sum);

int main()
{
    // ---------------- TASK 1 ----------------
    std::cout << "---------------- TASK 1 ----------------" << std::endl << std::endl;

    int x = 10;
    int y = 25;

    std::cout << "X: " << x << ", Y: " << y << std::endl;

    swap(x, y); 
    std::cout << "X: " << x << ", Y: " << y << std::endl;

    swap(&x, &y);
    std::cout << "X: " << x << ", Y: " << y << std::endl;

    std::cout << std::endl;

    // ---------------- TASK 2 ----------------
    std::cout << "---------------- TASK 2 ----------------" << std::endl << std::endl;

    double arrTrue[]{ 213.232, 3232.111, 764.05 };
    double sumTrue = 0.; 

    bool tru = calculateSum(arrTrue, sizeof(arrTrue) / sizeof(double), sumTrue);

    std::cout << "Size of the array is greater then " << static_cast<int>(!tru);
    std::cout << " and sum of its elements equals to " << sumTrue << std::endl << std::endl;

    double arrFalse[100];
    double sumFalse = 0.;

    bool fal = calculateSum(arrFalse, -99, sumFalse);

    std::cout << "Size of the array is less than or equals to " << static_cast<int>(fal);
    std::cout << " and sum of its elements equals to " << sumFalse << std::endl << std::endl;
}

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;

    std::cout << "Values swapped" << std::endl;
}

void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;

    std::cout << "Values swapped" << std::endl;
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