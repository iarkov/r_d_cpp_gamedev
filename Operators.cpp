#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    // ---------- TASK 1 ----------
    std::cout << "---------- Task 1 ----------\n" << std::endl;

    unsigned int seconds_prim;

    std::cout << "Enter how many seconds player was in game: "; 
    std::cin >> seconds_prim; 

    /*
    int hours = seconds_prim / 3600;
    int minutes = (seconds_prim - 3600 * hours) / 60;
    int seconds = seconds_prim % 60;
    */

    unsigned int seconds = seconds_prim % 60;
    unsigned int minutes = seconds_prim / 60 % 60;
    unsigned int hours = seconds_prim / 3600;

    std::cout << "Player was in game ";
    std::cout << hours << " hours ";
    std::cout << minutes << " minutes ";
    std::cout << seconds << " seconds\n" << std::endl;

    // ---------- TASK 2 ----------
    std::cout << "---------- Task 2 ----------\n" << std::endl;

    double number1Task2;
    double number2Task2;
    double number3Task2;

    std::cout << "Enter number 1: ";
    std::cin >> number1Task2;
    std::cout << "Enter number 2: ";
    std::cin >> number2Task2;
    std::cout << "Enter number 3: ";
    std::cin >> number3Task2;

    double sum = number1Task2 + number2Task2 + number3Task2;
    double product = number1Task2 * number2Task2 * number3Task2;
    double mean = sum / 3;
    
    std::cout << "\n";

    std::cout << "Sum of numbers: " << sum << std::endl;
    std::cout << "Product of numbers: " << product << std::endl;
    std::cout << "Mean value of numbers: " << mean << std::endl;

    std::cout << "\n";

    std::cout << "Number 1 is less then number 2: " << std::boolalpha << (number1Task2 < number2Task2) << std::endl;
    std::cout << "Number 1 is equal to number 2: " << std::boolalpha << (number1Task2 == number2Task2) << std::endl;
    std::cout << "Number 1 is more then number 2: " << std::boolalpha << (number1Task2 > number2Task2) << std::endl;

    std::cout << "\n";

    std::cout << "Number 2 is less then number 3: " << std::boolalpha << (number2Task2 < number3Task2) << std::endl;
    std::cout << "Number 2 is equal to number 3: " << std::boolalpha << (number2Task2 == number3Task2) << std::endl;
    std::cout << "Number 2 is more then number 3: " << std::boolalpha << (number2Task2 > number3Task2) << std::endl;

    std::cout << "\n";

    // ---------- TASK 3 ----------
    std::cout << "---------- Task 3 ----------\n" << std::endl;

    double number1Task3;
    double number2Task3;

    std::cout << "Enter number 1: ";
    std::cin >> number1Task3;
    std::cout << "Enter number 2: ";
    std::cin >> number2Task3;

    std::cout << "\n";

    bool lessThan = number1Task3 < number2Task3;
    bool lessOrEqual = number1Task3 <= number2Task3;
    bool equal = number1Task3 == number2Task3;
    bool moreOrEqual = number1Task3 >= number2Task3;
    bool moreThan = number1Task3 > number2Task3;

    std::cout << "\n";

    std::cout << "Number 1 is less than number 2: " << std::noboolalpha << lessThan << std::endl;
    std::cout << "Number 1 is less than or equal to number 2: " << lessOrEqual << std::endl;
    std::cout << "Number 1 is equal to number 2: " << equal << std::endl;
    std::cout << "Number 1 is more than or equal to number 2: " << moreOrEqual << std::endl;
    std::cout << "Number 1 is more than number 2: " << moreThan << std::endl;

    std::cout << "\n";

    std::cout << "Number 1 is less than number 2: " << std::boolalpha << lessThan << std::endl;
    std::cout << "Number 1 is less than or equal to number 2: " << lessOrEqual << std::endl;
    std::cout << "Number 1 is equal to number 2: " << equal << std::endl;
    std::cout << "Number 1 is more than or equal to number 2: " << moreOrEqual << std::endl;
    std::cout << "Number 1 is more than number 2: " << moreThan << std::endl;

    std::cout << "\n";

    // ---------- TASK 4 ----------
    std::cout << "---------- Task 4 ----------\n" << std::endl;

    double height;
    double width;

    std::cout << "Enter height of rectangle: ";
    std::cin >> height;
    std::cout << "Enter width of rectangle: ";
    std::cin >> width;
    
    double rectangleArea = height * width;
    double rectanglePerimeter = (height + width) * 2;

    std::cout << "\n";

    std::cout << "Area of rectangle: " << rectangleArea << std::endl;
    std::cout << "Perimeter of rectangle: " << rectanglePerimeter << std::endl;

    std::cout << "\n";

    // ---------- TASK 5 ----------
    std::cout << "---------- Task 5 ----------\n" << std::endl;

    double radius;

    std::cout << "Enter raduis of a circle: ";
    std::cin >> radius;

    double pi = 3.14159265358979323846;
    double circleArea = pi * radius * radius;
    double circumferenceLength = 2 * pi * radius;
    
    /*
    double circleArea = M_PI * radius * radius;
    double circumferenceLength = 2 * M_PI * radius;
    */

    std::cout << "\n";

    std::cout << "Area of the circle: " << circleArea << std::endl;
    std::cout << "Length of the circumference: " << circumferenceLength << std::endl;

    std::cout << "\n";
}

