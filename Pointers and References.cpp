#include <iostream>

void swap(int& a, int& b);

void swap(int* a, int* b);

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