#include <iostream>
#include <cctype>

const int arraySizeTask1 = 10;
const int arrayLength = 255;

void translateArray(int numbers[], int size);
void toUpperCase(char str[]);

int main()
{
    // --------------- TASK 1 ---------------
    std::cout << "--------------- TASK 1 ---------------" << std::endl << std::endl;
    int numberArray[arraySizeTask1]{0};

    std::cout << "Enter array of 10 numbers (with ' ' as separator): ";
    for (int i = 0; i < arraySizeTask1; i++) {
        std::cin >> numberArray[i];
    }

    translateArray(numberArray, arraySizeTask1);
    std::cout << std::endl << std::endl;

    // --------------- TASK 2 ---------------
    std::cout << "--------------- TASK 2 ---------------" << std::endl << std::endl;

    char charArrayTask2[arrayLength]{};

    std::cout << "Enter character array: ";
    std::cin >> charArrayTask2;

    std::cout << "Character array in upper case: " << std::endl;
    toUpperCase(charArrayTask2);
    std::cout << std::endl;
}

void translateArray(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        if (numbers[i] > 0) {
            std::cout << numbers[i] * 2 << " ";
        }
        else {
            std::cout << 0 << " ";
        }
    }
}

void toUpperCase(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (islower(str[i])) {
            std::cout << static_cast<char>(std::toupper(str[i]));
        }
        else {
            std::cout << static_cast<char>(str[i]);
        }
    }
}