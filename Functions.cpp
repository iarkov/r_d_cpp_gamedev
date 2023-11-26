#include <iostream>
#include "FunctionsHW8.h"


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

	// -------------- TASK 3 --------------
	std::cout << "-------------- TASK 3 --------------" << std::endl << std::endl;

	int naturalNumbers = 0;
	std::cout << "Enter a number of first natural numbers to show: "; 
	std::cin >> naturalNumbers;
	std::cout << std::endl;

	std::cout << "First " << naturalNumbers << " natural numbers in descending order using loops: " << std::endl;
	printNaturalNumbersA(naturalNumbers); std::cout << std::endl;
	std::cout << "First " << naturalNumbers << " natural numbers in ascending order using loops: " << std::endl;
	printNaturalNumbersB(naturalNumbers); std::cout << std::endl;
	std::cout << "First " << naturalNumbers << " natural numbers in descending order using recursion: " << std::endl;
	printNaturalNumbersC(naturalNumbers); std::cout << std::endl;
	std::cout << "First " << naturalNumbers << " natural numbers in ascending order using recursion: " << std::endl;
	printNaturalNumbersD(naturalNumbers); std::cout << std::endl;
}
