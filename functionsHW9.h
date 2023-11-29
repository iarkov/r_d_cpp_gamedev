#pragma once

#include <iostream>
#include <cctype>

const int arraySizeTask1 = 10;
const int arraySize = 255;

void translateArray(int numbers[], int size);
void toUpperCase(char str[]);
bool isPalindrom(const char str[]);
void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount);
bool isEqual(const char str1[], const char str2[]);