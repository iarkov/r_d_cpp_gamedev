#include <iostream>

enum class Month {
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

int main()
{
    // ---------- TASK 1 ----------
    std::cout << "---------- TASK 1 ----------\n" << std::endl;

    int number1Task1 = 0;
    int number2Task1 = 0;
    int number3Task1 = 0;

    std::cout << "Enter number 1: ";
    std::cin >> number1Task1;
    std::cout << "Enter number 2: ";
    std::cin >> number2Task1;
    std::cout << "Enter number 3: ";
    std::cin >> number3Task1;
    std::cout << "\n";

    if (number1Task1 >= number2Task1 && number1Task1 >= number3Task1) {
        std::cout << "Max number: " << number1Task1 << std::endl;
    }
    else if (number2Task1 >= number3Task1) {
        std::cout << "Max number: " << number2Task1 << std::endl;
    }
    else {
        std::cout << "Max number: " << number3Task1 << std::endl;
    }

    std::cout << "\n";

    // ---------- TASK 2 ----------
    std::cout << "---------- TASK 2 ----------\n" << std::endl;

    int number1Task2 = 0;
    int number2Task2 = 0;

    std::cout << "Enter number 1: ";
    std::cin >> number1Task2;
    std::cout << "Enter number 2: ";
    std::cin >> number2Task2;
    std::cout << "\n";

    int minNumberTask2 = (number1Task2 < number2Task2) ? number1Task2 : number2Task2;
    std::cout << "Min number: " << minNumberTask2 << std::endl;

    std::cout << "\n";

    // ---------- TASK 3 ----------
    std::cout << "---------- TASK 3 ----------\n" << std::endl;

    int number = 0;

    std::cout << "Enter number: ";
    std::cin >> number;
    std::cout << "\n";

    if (number % 5 == 0 && number % 11 == 0)
    {
        std::cout << "Number " << number << " is divided by 5 and by 11 without remainder" << std::endl;
    } else 
    {
        std::cout << "Number " << number << " is divided by 5 or by 11 with remainder" << std::endl;
    }

    std::cout << "\n";

    // ---------- TASK 4 ----------
    std::cout << "---------- TASK 4 ----------\n" << std::endl;

    double number1Task4 = 0;
    double number2Task4 = 0;
    double number3Task4 = 0;

    std::cout << "Enter angle 1 degrees : ";
    std::cin >> number1Task4;
    std::cout << "Enter angle 2 degrees : ";
    std::cin >> number2Task4;
    std::cout << "Enter angle 3 degrees: ";
    std::cin >> number3Task4;
    std::cout << "\n";

    if (number1Task4 > 0 && number2Task4 > 0 && number3Task4 > 0 && (number1Task4 + number2Task4 + number3Task4) == 180)
    {
        std::cout << "Corners 1, 2 and 3 form a triangle";
    }
    else
    {
        std::cout << "Corners 1, 2 and 3 do not form a triangle";
    }

    std::cout << "\n";

    // ---------- TASK 5 ----------
    std::cout << "---------- TASK 5 ----------\n" << std::endl;

    int numberTask5 = 0;

    std::cout << "Enter number of the month: ";
    std::cin >> numberTask5;
    std::cout << "\n";

    Month monthTask5 = static_cast<Month>(numberTask5);

    switch (monthTask5)
    {
        case Month::January: 
        {
            std::cout << "January" << std::endl;
            break;
        }
        case Month::February:
        {
            std::cout << "February" << std::endl;
            break;
        }
        case Month::March:
        {
            std::cout << "March" << std::endl;
            break;
        }
        case Month::April:
        {
            std::cout << "April" << std::endl;
            break;
        }
        case Month::May:
        {
            std::cout << "May" << std::endl;
            break;
        }
        case Month::June:
        {
            std::cout << "June" << std::endl;
            break;
        }
        case Month::July:
        {
            std::cout << "July" << std::endl;
            break;
        }
        case Month::August:
        {
            std::cout << "August" << std::endl;
            break;
        }
        case Month::September:
        {
            std::cout << "September" << std::endl;
            break;
        }
        case Month::October:
        {
            std::cout << "October" << std::endl;
            break;
        }
        case Month::November:
        {
            std::cout << "November" << std::endl;
            break;
        }
        case Month::December:
        {
            std::cout << "December" << std::endl;
            break;
        }
        default: 
        {
            std::cout << "Unfortunately, you have entered wrong number" << std::endl;
            break;
        }
    }

    std::cout << "\n";

    // ---------- TASK 6 ----------
    std::cout << "---------- TASK 6 ----------\n" << std::endl;

    int numberTask6 = 0;

    std::cout << "Enter number of the month: ";
    std::cin >> numberTask6;
    std::cout << "\n";

    Month monthTask6 = static_cast<Month>(numberTask6);

    switch (monthTask6)
    {
        case Month::January:
        case Month::February:
        case Month::December:
        {
            std::cout << "Winter" << std::endl;
            break;
        }
        case Month::March:
        case Month::April:
        case Month::May:
        {
            std::cout << "Spring" << std::endl;
            break;
        }
        case Month::June:
        case Month::July:
        case Month::August:
        {
            std::cout << "Summer" << std::endl;
            break;
        }
        case Month::September:
        case Month::October:
        case Month::November:
        {
            std::cout << "Autumn" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Unfortunately, you have entered wrong number" << std::endl;
            break;
        }
    }
}
