#include <iostream>
#include "DynamicIntArray.h"

int main()
{
	DynamicIntArray arr1;
	arr1.setSize(10);
	DynamicIntArray arr2 = arr1;
	DynamicIntArray arr3(20);
	std::cout << arr3[19] << " " << arr3.getSize() << std::endl;
	arr3 = arr1;
	std::cout << arr1[9] << " " << arr2[9] << " " << arr3[9] << " " << arr3.getSize() << std::endl;

	arr1.clear();
	std::cout << arr1.getSize() << std::endl;

	arr1.push_back(10);
	std::cout << arr1.getSize() << " " << arr1[arr1.getSize()-1] << std::endl;
}
