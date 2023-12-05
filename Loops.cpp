#include <iostream>
#include <ctype.h>

int main()
{
    // ---------- TASK 1 ----------
    std::cout << "---------- TASK 1 ----------" << std::endl << std::endl;

    int arProgression1;
    int step;
    int arProgressionN;

    std::cout << "Enter first element of ariphmetic progression: ";
    std::cin >> arProgression1;
    std::cout << "Enter step value: ";
    std::cin >> step;
    std::cout << "Enter last element of ariphmetic progression: ";
    std::cin >> arProgressionN;
    std::cout << std::endl;

    if (
        step == 0 || // No step -> infinite sequence
        (arProgressionN - arProgression1) < (arProgressionN - (arProgression1 + step)) || // Progression goes in wrong direction
        (arProgressionN - arProgression1) % step != 0 || // Last number does not belong to sequence
        arProgression1 == arProgressionN // First number equals to last number -> no sequence
    ) {
        std::cout << "Entered elements don't create ariphmetic progression" << std::endl;
    }
    else {
        std::cout << "Ariphmetic progression: " << arProgression1 << " ";

        do {
            arProgression1 += step;
            std::cout << arProgression1 << " ";
        } while (arProgression1 != arProgressionN);
    }
    
    std::cout << std::endl << std::endl;

    // ---------- TASK 2 ----------
    std::cout << "---------- TASK 2 ----------" << std::endl << std::endl;

    unsigned int fibonacciNumber;

    std::cout << "Enter number of the element of the Fibonacci sequence: ";
    std::cin >> fibonacciNumber;
    std::cout << std::endl;

    if (fibonacciNumber == 1 || fibonacciNumber == 2) {
        std::cout << "Fibonacci sequence element: " << 1 << std::endl << std::endl;
    }
    else {
        int element1 = 1;
        int element2 = 1;
        int swap;

        for (int i = 3; i <= fibonacciNumber; i++) {
            swap = element2;
            element2 = element2 + element1;
            element1 = swap;
        }

        std::cout << "Fibonacci sequence element: " << element2 << std::endl << std::endl;
    }

    // ---------- TASK 3 ----------
    std::cout << "---------- TASK 3 ----------" << std::endl << std::endl;

    unsigned int factorialNumber;

    std::cout << "Enter number: ";
    std::cin >> factorialNumber;
    std::cout << std::endl;

    int factorial = 1;

    for (int i = 1; i <= factorialNumber; i++) {
        factorial = factorial * i;
    }

    std::cout << "Factorial of the entered number: " << factorial << std::endl << std::endl;

    // ---------- TASK 4 ----------
    std::cout << "---------- TASK 4 ----------" << std::endl << std::endl;

    // ---------- A ----------
    unsigned int heightA;
    unsigned int widthA;

    std::cout << "Enter height of figure A: "; 
    std::cin >> heightA;
    std::cout << "Enter width of figure A: ";
    std::cin >> widthA;
    std::cout << std::endl;

    for (int i = heightA; i > 0; i--) {
        for (int j = widthA; j > 0; j--) {
            std::cout << '*';
        }
        std::cout << std::endl;
        --widthA;
        if (widthA == 0) {
            break;
        }
    }
    std::cout << std::endl << std::endl;

    // ---------- B ----------
    int heightB;
    int widthB;

    std::cout << "Enter height of figure B: ";
    std::cin >> heightB;
    std::cout << "Enter width of figure B: ";
    std::cin >> widthB;
    std::cout << std::endl;

    for (int i = 0; i < heightB; i++) {
        
        if (heightB - i > widthB) {
            continue;
        }
        
        for (int j = 0; j <= (widthB - (heightB - i)); j++) {
            std::cout << '*';
        }

        if (i < heightB - 1) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    // ---------- C ----------
    int heightC;
    int widthC;

    std::cout << "Enter height of figure C: ";
    std::cin >> heightC;
    std::cout << "Enter width of figure C: ";
    std::cin >> widthC;
    std::cout << std::endl;

    for (int i = 0; i < heightC; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << ' ';
        }

        for (int w = 0; w < widthC; w++) {
            std::cout << "*";
        }

        if (i < heightC - 1) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    // ---------- D ---------- 
    int heightD;
    int widthD;

    std::cout << "Enter height of figure D: ";
    std::cin >> heightD;
    std::cout << "Enter width of figure D: ";
    std::cin >> widthD;
    std::cout << std::endl;

    if (heightD > widthD) {
        heightD = widthD;
    }

    for (int i = 1; i <= heightD; i++) {

        for (int j = 1; j <= (widthB - (heightB - i)); j++) {
            if ((i - j) % 2 == 0) {
                std::cout << 1;
            }
            else {
                std::cout << 0;
            }
        }

        if (i <= heightB) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    // ---------- TASK 5 ----------
    std::cout << "---------- TASK 5 ----------" << std::endl << std::endl;

    char c;
    int sum = 0;

    while (true) {
        std::cout << "Enter character: ";
        std::cin >> c;
        if (c == '.') {
            break;
        }
        else if (isalpha(c) && islower(c)) {
            std::cout << "Entered letter in uppercase: " << static_cast<char>(toupper(c)) << std::endl;
        }
        else if (isdigit(c)) {
            sum = sum + c - '0';
            std::cout << "The sum of entered numbers: " << sum << std::endl;
        }
        else {
            std::cout << "Entered symbol cannot be processed." << std::endl;
        }
    }
}

