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
        (arProgressionN - arProgression1) <= (arProgressionN - (arProgression1 + step)) || 
        (arProgressionN - arProgression1) % step != 0
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
}

