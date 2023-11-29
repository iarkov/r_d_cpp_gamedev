#include <iostream>
#include <cctype>

const int arraySizeTask1 = 10;
const int arraySize = 255;

void translateArray(int numbers[], int size);
void toUpperCase(char str[]);
bool isPalindrom(const char str[]);
void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount);
//bool isEqual(const char str1[], const char str2[]);

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
        if (str[j] == ' ' || str[j] == '\0') {
            break;
        }
        else {
            wordLength++;
        }
    }
    
    for (int i = 0; i <= wordLength - i; i++) {
        if (str[i] != str[wordLength - i]) {
            return false;
            break;
        }
    }
    return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount) {
    int i = 0;

    while (str[i] != ' ' && str[i] != '\0') {
        bool isAlpha = std::isalpha(str[i]);
        bool isVowel = std::tolower(str[i]) == 'a' ||
            std::tolower(str[i]) == 'e' ||
            std::tolower(str[i]) == 'o' ||
            std::tolower(str[i]) == 'u' ||
            std::tolower(str[i]) == 'i';

        if (isAlpha && isVowel) {
            vowelsCount++;
        }
        else if (isAlpha && !isVowel){
            consonantsCount++;
        }

        i++;
    }
}

//bool isEqual(const char str1[], const char str2[]) {
//    if (strlen(str1) == strlen(str2)) {
//        
//    }
//}