#include <iostream>

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


int main()
{
	// -------------- TASK 1 --------------
	std::cout << "-------------- TASK 1 --------------" << std::endl << std::endl;

	int numberCBS = 0;
	std::cout << "Enter number for function coutnBySigh(): "; 
	std::cin >> numberCBS;
	countBySign(numberCBS);

	std::cout << std::endl;
}
