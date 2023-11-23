#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));

    const int generatingRange = 50;
    int generatedNum = std::rand() % (generatingRange + 1);

    std::cout << "Welcome to a brand NEW game \"Guess the Number\"!!!" << std::endl;
    std::cout << "The number to guess varies from 0 to 50. Good luck!" << std::endl;
    std::cout << "Reminder: to quit the game enter \"-1\" or blank value" << std::endl << std::endl;

    int score = 0;
    int championScore = 0;
    
    while (true) {
        int guessNumber = -1;
        std::cout << "Please, enter your number: ";
        std::cin >> guessNumber;
        score++;

        if (guessNumber == -1) {
            std::cout << "You have chosen to leave our brand NEW game :( Shame on you!" << std::endl;
            break;
        }
        else if (guessNumber < -1 || guessNumber > generatingRange) {
            std::cout << "Your number does not fit our generating range. Next time be more attentive!" << std::endl << std::endl;
        }
        else if (guessNumber == generatedNum) {
            std::cout << "Good for you!!! " << guessNumber << " is the right number! It took " << score << " attemps to guess the number." << std::endl;
            championScore = (championScore > score || championScore == 0) ? score : championScore;
            score = 0;
            std::cout << "Your BEST score is " << championScore << " attemps!" << std::endl;
            std::cout << "Now let's guess anouther number!" << std::endl << std::endl;

            generatedNum = std::rand() % (generatingRange + 1);
        }
        else if ((guessNumber - generatedNum) > 20) {
            std::cout << "Your number is TOO MUCH HIGH! Try a LOWER one." << std::endl << std::endl;
        }
        else if ((guessNumber - generatedNum) > 10 ) {
            std::cout << "Your number is a LITTLE TOO HIGH. Try a BIT LOWER one." << std::endl << std::endl;
        }
        else if ((guessNumber - generatedNum) > 0) {
            std::cout << "You're so CLOSE! But your number is STILL A LITTLE TOO HIGH. Try a LITTLE BIT LOWER one." << std::endl << std::endl;
        }
        else if ((generatedNum - guessNumber) > 20) {
            std::cout << "Your number is TOO MUCH LOW! Try a HIGHER one." << std::endl << std::endl;
        }
        else if ((generatedNum - guessNumber) > 10) {
            std::cout << "Your number is a LITTLE TOO LOW. Try a BIT HIGHER one." << std::endl << std::endl;
        }
        else if ((generatedNum - guessNumber) > 0) {
            std::cout << "You're so CLOSE! But your number is STILL A LITTLE TOO LOW. Try a LITTLE BIT HIGHER one." << std::endl << std::endl;
        }
    }
}
