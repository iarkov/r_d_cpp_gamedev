#include <iostream>
#include <cctype>

const int arraySizeTask1 = 10;
const int arraySizeTask2 = 255;
const int arraySizeTask3 = 255;

void translateArray(int numbers[], int size);
void toUpperCase(char str[]);
bool isPalindrom(const char str[]);

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

    char charArrayTask2[arraySizeTask2]{};

    std::cout << "Enter character array: ";
    std::cin >> charArrayTask2;

    std::cout << "Character array in upper case: " << std::endl;
    toUpperCase(charArrayTask2);
    std::cout << std::endl << std::endl;

    // --------------- TASK 3 ---------------
    std::cout << "--------------- TASK 3 ---------------" << std::endl << std::endl;

    char stringTask3[arraySizeTask3]{};
    std::cout << "Enter a word: "; std::cin >> stringTask3;

    if (isPalindrom(stringTask3)) {
        std::cout << "The word is a palindrom";
    }
    else {
        std::cout << "The word is not a palindrom";
    }
    std::cout << std::endl << std::endl;

    // --------------- TASK 4 ---------------
    std::cout << "--------------- TASK 4 ---------------" << std::endl << std::endl;
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

bool isPalindrom(const char str[]) {
    int wordLength = -1; 
    for (int j = 0; j <= strlen(str); j++) {
        if (str[j] == ' ') {
            break;
        }
        else {
            wordLength++;
        }
    }
    
    for (int i = 0; i <= wordLength - 1 - i; i++) {
        if (str[i] != str[wordLength - 1 - i]) {
            return false;
            break;
        }
    }
    return true;
}