#include "FunctionsHW8.h"
#include <iostream>

int factorialRec(unsigned int count) {
	return (count == 0) ? 1 : count * factorialRec(count - 1);
}

int factorialLoop(unsigned int count) {

	int factorial = 1;

	if (count == 0) {
		return factorial;
	}

	while (count > 0) {
		factorial = factorial * count;
		count--;
	}

	return factorial;
}

void countBySign(int n) {
	int number = 0;
	int positives = 0;
	int negatives = 0;
	int zeros = 0;

	std::cout << "Enter numbers: ";

	for (int i = 0; i < n; i++) {
		std::cin >> number;

		if (number > 0) {
			positives++;
		}
		else if (number < 0) {
			negatives++;
		}
		else {
			zeros++;
		}
	}

	std::cout << std::endl;
	std::cout << "You entered " << zeros << " zeros, " << positives << " positive and " << negatives << " negative numbers." << std::endl;
}

void printNaturalNumbersA(int count) {
	while (count > 0) {
		std::cout << count << " ";
		count--;
	}
}

void printNaturalNumbersB(int count) {
	int i = 1;

	while (i <= count) {
		std::cout << i << " ";
		i++;
	}
}

void printNaturalNumbersC(int count) {
	if (count == 1) {
		std::cout << count <<  " ";
	}
	else {
		std::cout << count << " ";
		printNaturalNumbersC(count - 1);
	}
}

void printNaturalNumbersD(int count) {
	if (count == 1) {
		std::cout << count << " ";
	}
	else {
		printNaturalNumbersD(count - 1);
		std::cout << count << " ";
	}
}