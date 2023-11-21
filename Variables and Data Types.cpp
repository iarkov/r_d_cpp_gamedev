// Variables and Data Types.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

enum class Weekday {
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

int main()
{
    // Task 1
    std::cout << "Task #1\n\n";

    int number1;
    int number2;

    try {
        std::cout << "Enter integer 1: ";
        std::cin >> number1;
        std::cout << "Enter integer 2: ";
        std::cin >> number2;

        /*
        int numberSwap = number1;

        number1 = number2;
        number2 = numberSwap;
        */
        std::swap(number1, number2);

        std::cout << "Integer 1: " << number1 << "\nInteger 2: " << number2 << "\n\n";
    }
    catch (...) {
        std::cout << "You've broken a program, shame on you!\n";
    }

    // Task 2
    std::cout << "Task #2\n\n";

    double double_number_task2 = 8220.7282;
    std::cout << "Double number: " << double_number_task2 << std::endl;
    std::cout << "Double number converted to integer: " << static_cast<int>(double_number_task2) << std::endl;
    std::cout << std::setw(20) << std::right << std::setfill('$') << double_number_task2 << std::endl << std::endl;

    // Task 3
    std::cout << "Task #3\n\n";

    double doubleNumberTask3 = 264.13656648616464;

    std::cout << "Double Number with precision 2: " << std::setprecision(2) << doubleNumberTask3 << std::endl;
    std::cout << "Double Number with precision 5: " << std::setprecision(5) << doubleNumberTask3 << std::endl;
    std::cout << "Double Number with precision 10: " << std::setprecision(10) << doubleNumberTask3 << std::endl;

    std::cout << "Double Number in Standard Notation: " << std::fixed << doubleNumberTask3 << std::endl;
    std::cout << "Double Number in E Notation: " << std::scientific << doubleNumberTask3 << std::endl << std::endl;

    // Task 4
    std::cout << "Task #4\n\n";

    std::cout << "Monday's Number: " << static_cast<int>(Weekday::Monday) << std::endl;
    std::cout << "Tuesday's Number: " << static_cast<int>(Weekday::Tuesday) << std::endl;
    std::cout << "Wednesday's Number: " << static_cast<int>(Weekday::Wednesday) << std::endl;
    std::cout << "Thursday's Number: " << static_cast<int>(Weekday::Thursday) << std::endl;
    std::cout << "Friday's Number: " << static_cast<int>(Weekday::Friday) << std::endl;
    std::cout << "Saturday's Number: " << static_cast<int>(Weekday::Saturday) << std::endl;
    std::cout << "Sunday's Number: " << static_cast<int>(Weekday::Sunday) << std::endl << std::endl;

    // Task 5
    std::cout << "Task #5\n\n";

    int numberTask5 = 0;
    std::cout << "Enter Number: "; 
    std::cin >> numberTask5; 

    std::cout << "Number converted to bool: " << std::boolalpha << static_cast<bool>(numberTask5) << std::endl;

    return 0;
}

