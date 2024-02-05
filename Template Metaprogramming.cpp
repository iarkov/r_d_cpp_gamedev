#include <iostream>
#include "DynamicArray.h"
#include <string>

int main()
{
	std::cout << "--------------------------- ARR1 ---------------------------" << std::endl << std::endl;

	DynamicArray<int> arr1; // Initializing dynamic int array
	std::cout << arr1.getSize() << " " << arr1.getCapacity() << std::endl; // printing current size (0) and capacity (0) of the array
	arr1.reserve(3); // reserving space for three members of the array
	std::cout << arr1.getSize() << " " << arr1.getCapacity() << std::endl; // printing current size (0) and capacity (3) of the array
	arr1.push_back(0); // Pushing back the value of 0
	std::cout << arr1.back() << " " << arr1.getSize() << " " << arr1.getCapacity() << std::endl; // printing the last member of the array (0), current size (1) and capacity (3) of the array
	arr1.push_back(1); // Pushing back the value of 1
	std::cout << arr1.back() << " " << arr1.getSize() << " " << arr1.getCapacity() << std::endl; // printing the last member of the array (1), current size (2) and capacity (3) of the array
	arr1.push_back(2); // Pushing back the value of 2
	std::cout << arr1.back() << " " << arr1.getSize() << " " << arr1.getCapacity() << std::endl; // printing the last member of the array (2), current size (3) and capacity (3) of the array
	arr1.pop_back(); // Popping back the last value of the array
	std::cout << arr1.back() << " " << arr1.getSize() << " " << arr1.getCapacity() << std::endl; // printing the last member of the array (1), current size (2) and capacity (2) of the array. Capacity decreased by 1, because previously size got the level of capacity
	arr1.reserve(3); // reserving space for three members of the array
	std::cout << arr1.back() << " " << arr1.getSize() << " " << arr1.getCapacity() << std::endl; // printing the last member of the array (1), current size (2) and capacity (3) of the array
	arr1.pop_back(); // Popping back the last value of the array
	std::cout << arr1.back() << " " << arr1.getSize() << " " << arr1.getCapacity() << std::endl; // printing the last member of the array (0), current size (1) and capacity (3) of the array. Capacity left the same.
	arr1.reserve(2); // reserving space for two members of the array
	std::cout << arr1.back() << " " << arr1.getSize() << " " << arr1.getCapacity() << std::endl; // printing the last member of the array (0), current size (1) and capacity (3) of the array. Capacity left the same, because array has already had reserved more places, than we tried to.
	std::cout << std::endl;

	std::cout << "--------------------------- ARR2 ---------------------------" << std::endl << std::endl;

	DynamicArray<int> arr2 = arr1; // creating new dynamic array with a copy constructor
	std::cout << arr2.back() << " " << arr2.getSize() << " " << arr2.getCapacity() << std::endl << std::endl; // printing the last member of the array (0), current size (1) and capacity (3) of the array.

	std::cout << "--------------------------- ARR3 ---------------------------" << std::endl << std::endl;

	DynamicArray<int> arr3; // creating new dynamic array
	std::cout << arr3.getSize() << " " << arr3.getCapacity() << std::endl; // printing current size (0) and capacity (0) of the array
	arr3.setSize(5);
	std::cout << arr3.back() << " " << arr3.getSize() << " " << arr3.getCapacity() << std::endl; // printing the last member of the array (0), current size (5) and capacity (5) of the array. 
	arr3 = arr1; // using assignment operator
	std::cout << arr3.back() << " " << arr3.getSize() << " " << arr3.getCapacity() << std::endl; // printing the last member of the array (0), current size (1) and capacity (3) of the array.
	std::cout << (arr2 == arr3) << std::endl; // Equal operator returns true
	arr3.pop_back(); 
	std::cout << arr3.getSize() << " " << arr3.getCapacity() << std::endl; // printing current size (0) and capacity (3) of the array
	arr3.pop_back();// No actual popping back, because size the array is already empty
	std::cout << arr3.getSize() << " " << arr3.getCapacity() << std::endl; // printing current size (0) and capacity (3) of the array
	arr3.push_back(2);
	std::cout << arr3.back() << " " << arr3.getSize() << " " << arr3.getCapacity() << std::endl; // printing the last member of the array (2), current size (1) and capacity (3) of the array.
	std::cout << (arr2 == arr3) << std::endl; // Equal operator returns false
	arr3.shrinkToFit();
	std::cout << arr3.back() << " " << arr3.getSize() << " " << arr3.getCapacity() << std::endl; // printing the last member of the array (2), current size (1) and capacity (1) of the array.
	arr3.shrinkToFit();
	std::cout << arr3.back() << " " << arr3.getSize() << " " << arr3.getCapacity() << std::endl; // Features of the array left the same. Capacity is already equal to size
	std::cout << std::endl;

	std::cout << "--------------------------- ARR4 ---------------------------" << std::endl << std::endl;

	DynamicArray<std::string> arr4(1); // creating new array with the size of 1
	arr4.push_back("string");
	std::cout << ((arr4[0] == "") ? "empty" : arr4[0]) << " " << arr4[1] << std::endl; // Printing the first and the second elements of the array
	arr4.setSize(1);
	std::cout << arr4.back() << " " << arr4.getSize() << " " << arr4.getCapacity() << std::endl; // Features of the array left the same, because the size can only be increased by setSize(). Although, the size can be lowered by popping back the elements
}