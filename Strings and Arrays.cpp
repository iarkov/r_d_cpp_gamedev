#include <iostream>
#include <cctype>

const int arrayLength = 255;

void toUpperCase(char str[]);

int main()
{
    // --------------- TASK 2 ---------------
    std::cout << "--------------- TASK 2 ---------------" << std::endl << std::endl;

    char str[arrayLength];

    std::cout << "Enter character array: ";
    std::cin.getline(str, arrayLength);

    std::cout << "Character array in upper case: " << std::endl;
    toUpperCase(str);
    std::cout << std::endl;
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