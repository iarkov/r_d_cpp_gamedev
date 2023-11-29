#include "functionsHW9.h"

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
        else if (isAlpha && !isVowel) {
            consonantsCount++;
        }

        i++;
    }
}

bool isEqual(const char str1[], const char str2[]) {
    if (strlen(str1) == strlen(str2)) {
        int i = 0;
        while (str1[i] != '\0') {
            if (str1[i] != str2[i]) {
                return false;
            }
            return true;
        }
    }
    else {
        return false;
    }
}