#include <iostream>

int factorialRec(unsigned int count);

int factorialLoop(unsigned int count);

void countBySign(int n);


int main()
{
	// -------------- TASK 1 --------------
	std::cout << "-------------- TASK 1 --------------" << std::endl << std::endl;

	int numberCBS = 0;
	std::cout << "Enter number for function coutnBySigh(): "; 
	std::cin >> numberCBS;
	countBySign(numberCBS);

	std::cout << std::endl;

	// -------------- TASK 2 --------------
	std::cout << "-------------- TASK 2 --------------" << std::endl << std::endl;

	int numberFactorial = 0;
	std::cout << "Enter number for function factorial(): ";
	std::cin >> numberFactorial;

	int factorialA = factorialRec(numberFactorial);
	std::cout << "Factorial based on recursion equals to " << factorialA << ".";
	std::cout << std::endl;

	int factorialB = factorialLoop(numberFactorial);
	std::cout << "Factorial based on loops equals to " << factorialB << ".";
	std::cout << std::endl << std::endl;
}

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