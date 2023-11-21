#include <iostream>

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
}

