#include <iostream>
#include <cctype>
#include "functionsHW9.h"

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

    char charArrayTask2[arraySize]{};

    std::cout << "Enter character array: ";
    std::cin >> charArrayTask2;

    std::cout << "Character array in upper case: " << std::endl;
    toUpperCase(charArrayTask2);
    std::cout << std::endl << std::endl;

    // --------------- TASK 3 ---------------
    std::cout << "--------------- TASK 3 ---------------" << std::endl << std::endl;

    char stringTask3[arraySize]{};
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

    int vowelsCount = 0;
    int consonantsCount = 0;

    char stringTask4[arraySize]{};
    std::cout << "Enter a word: "; std::cin >> stringTask4;

    parseStringLetters(stringTask4, vowelsCount, consonantsCount);

    std::cout << "Character string has " << vowelsCount << " vowels and " << consonantsCount << " consonants.";

    std::cout << std::endl << std::endl;

    // --------------- TASK 5 ---------------
    std::cout << "--------------- TASK 5 ---------------" << std::endl << std::endl;

    char str1[arraySize]{};
    char str2[arraySize]{};

    std::cout << "Enter character string 1: "; std::cin >> str1;
    std::cout << "Enter character string 2: "; std::cin >> str2;

    if (isEqual(str1, str2)) {
        std::cout << str1 << " is equal to " << str2;
    }
    else {
        std::cout << str1 << " is not equal to " << str2;
    }

    std::cout << std::endl;
}
