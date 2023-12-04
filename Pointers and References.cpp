#include <iostream>
#include "functionsHW10.h"

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

    double arrFalse[100]{};
    double sumFalse = 0.;
    
    bool fal = calculateSum(arrFalse, 0, sumFalse);

    std::cout << "Size of the array is less than or equals to " << static_cast<int>(fal);
    std::cout << " and sum of its elements equals to " << sumFalse << std::endl << std::endl;

    // ---------------- TASK 3 ----------------
    std::cout << "---------------- TASK 3 ----------------" << std::endl << std::endl;

    int arrFind[]{ 1, 2, -2 }; 
    bool found = find(arrFind, sizeof(arrFind) / sizeof(int), 1);
    
    if (found) {
        std::cout << "Element found";
    }
    else {
        std::cout << "Element not found";
    }

    std::cout << std::endl;
}
