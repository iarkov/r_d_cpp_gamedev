#include "FunctionsHW8.h"

int factorialRec(unsigned int count) {
	return (count == 0) ? 1 : count * factorialRec(count - 1);
}

int factorialLoop(unsigned int count) {

	int factorial = 1;

	if (count == 0) {
		return factorial;
	}
	else {
		while (count > 0) {
			factorial = factorial * count;
			count--;
		}

		return factorial;
	}
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
	std::cout << std::endl;
}
void printNaturalNumbersB(int count) {
	int i = 1;

	while (i <= count) {
		std::cout << i << " ";
		i++;
	}

	std::cout << std::endl;
}
void printNaturalNumbersC(int count) {
	if (count == 1) {
		std::cout << count << std::endl;
	}
	else {
		std::cout << count << " ";
		printNaturalNumbersC(count - 1);
	}
}

void helpFunctionD(int count, int i = 1) {
	if (i == count) {
		std::cout << i << std::endl;
	}
	else {
		std::cout << i << " ";
		helpFunctionD(count, i + 1);
	}
}

void printNaturalNumbersD(int count) {
	helpFunctionD(count);
}