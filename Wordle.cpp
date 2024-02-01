#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <ctime>

enum class GameMode {
    exit = 0,
    wordleOfTheDay = 1,
    randomWordle = 2
};

constexpr int WORD_SIZE = 5;
constexpr int WORD_ARRAY_SIZE = 6;
constexpr int WORDS_COUNT = 3374;
constexpr int DATE_SIZE = 11;

char** databasePtr = new char* [WORDS_COUNT];
char word[WORD_ARRAY_SIZE]{};

bool isEqual(const char* a, const char* b);
int getDay(const std::tm* tmObj);
int getMonth(const std::tm* tmObj);
int getYear(const std::tm* tmObj);

void initGame();
void runWordle();
void runGame(GameMode gm);

int main()
{
    initGame();
    runWordle();
}

void initGame() {
    std::ifstream fiveLetterNounsFile;
    fiveLetterNounsFile.open("five_letter_nouns.txt");

    if (!fiveLetterNounsFile) {
        std::cout << "File not found";
    }
    else {
        char word[WORD_ARRAY_SIZE]{};
        fiveLetterNounsFile >> std::noskipws;

        for (int i = 0; i < WORDS_COUNT; i++) {
            databasePtr[i] = new char[WORD_ARRAY_SIZE];
            fiveLetterNounsFile.getline(databasePtr[i], WORD_ARRAY_SIZE, '\n');
        }
    }

    std::cout << "Welcome to WORDLE!!!" << std::endl << std::endl;
}

void runWordle() {

    std::cout << "Please, choose your option:" << std::endl;
    std::cout << "1 - Wordle of the Day" << std::endl;
    std::cout << "2 - Random Wordle" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    std::cout << "Enter: ";

    int option;
    std::cin >> option;

    std::cout << std::endl;

    GameMode gm = static_cast<GameMode>(option);

    switch (gm) {
    case GameMode::exit:
        std::cout << "Have a nice day!" << std::endl;
        break;
    case GameMode::wordleOfTheDay:
    {
        std::fstream fileWordleOfTheDay;
        fileWordleOfTheDay.open("WordleOfTheDay.txt", std::ios::in);
        char date[DATE_SIZE]{};
        char passed[2];

        if (!fileWordleOfTheDay.is_open()) {
            std::cout << "File not found" << std::endl;
        }
        else {
            fileWordleOfTheDay.getline(date, DATE_SIZE, ';');
            fileWordleOfTheDay.getline(word, WORD_ARRAY_SIZE, ';');
            fileWordleOfTheDay.getline(passed, 2);

            fileWordleOfTheDay.close();

            std::time_t t = std::time(nullptr);
            struct std::tm* now = std::localtime(&t);
            char now_str[DATE_SIZE];
            std::strftime(now_str, DATE_SIZE, "%Y-%m-%d", now);

            if ((passed[0] - '0') && isEqual(date, now_str)) {
                std::cout << "You have already passed your Wordle of the Day today! Please, choose another option." << std::endl << std::endl;
                runWordle();
            }
            else if (!strlen(date) || !isEqual(date, now_str)) {
                int seed = getYear(now) + getMonth(now) + getDay(now);

                std::srand(seed);
                int random_int = std::rand() % WORDS_COUNT;

                for (int i = 0; i < WORD_ARRAY_SIZE; i++) {
                    word[i] = std::toupper(databasePtr[random_int][i]);
                }

                fileWordleOfTheDay.open("WordleOfTheDay.txt", std::ios::out | std::ios::trunc);

                fileWordleOfTheDay << getYear(now) << '-' << getMonth(now) << '-' << getDay(now) << ';';
                fileWordleOfTheDay << word << ';' << 0;

                fileWordleOfTheDay.close();

                runGame(gm);
            }
        }
        break;
    }
    case GameMode::randomWordle:
    {
        std::srand(time(nullptr));
        int word_number = std::rand() % WORDS_COUNT;
        for (int i = 0; i < WORD_ARRAY_SIZE; i++) {
            word[i] = std::toupper(databasePtr[word_number][i]);
        }
        runGame(gm);
        break;
    }
    default:
        std::cout << "You chose wrong option." << std::endl << std::endl;
        runWordle();
        break;
    }
}

void runGame(GameMode gm) {
    std::map<char, int> wordMap;

    for (int i = 0; i < WORD_SIZE; i++) {
        wordMap[word[i]] += 1;
    }

    char wordShow[6] = "*****";
    int ii = 1;

    while (ii < 6) {
        char guessWord[WORD_ARRAY_SIZE];
        std::cout << "RESULT: " << wordShow << std::endl << std::endl;
        std::cout << "ENTER: ";
        std::cin >> guessWord;

        for (int idx = 0; idx < WORD_SIZE; idx++) {
            guessWord[idx] = std::toupper(guessWord[idx]);
        }

        std::map<char, int> guessWordMap;

        for (int j = 0; j < 5; j++) {

            if (word[j] == guessWord[j]) {
                wordShow[j] = word[j];
                guessWordMap[guessWord[j]] += 1;
            }
            else {
                wordShow[j] = '*';
            }
        }

        for (int y = 0; y < 5; y++) {
            if (wordShow[y] == '*') {
                guessWordMap[guessWord[y]] += 1;

                if (wordMap[guessWord[y]] >= guessWordMap[guessWord[y]]) {
                    wordShow[y] = std::tolower(guessWord[y]);
                }
            }
        }


        if (isEqual(word, guessWord)) {
            std::cout << std::endl;
            switch (gm) {
            case GameMode::wordleOfTheDay: {
                char date[DATE_SIZE]{};
                std::fstream fileWordleOfTheDay;
                fileWordleOfTheDay.open("WordleOfTheDay.txt", std::ios::in);

                fileWordleOfTheDay.getline(date, DATE_SIZE, ';');
                fileWordleOfTheDay.close();

                fileWordleOfTheDay.open("WordleOfTheDay.txt", std::ios::out | std::ios::trunc);

                fileWordleOfTheDay << date << ';';
                fileWordleOfTheDay << word << ';' << 1;

                fileWordleOfTheDay.close();

                std::cout << "Congratulations!!! You guessed the word " << word << " with " << ii << " tries !" << std::endl;
                std::cout << "Would you try another game?" << std::endl << std::endl << std::endl;
                break;
            }
            default: {
                std::cout << "Congratulations!!! You guessed the word " << word << " with " << ii << " tries !" << std::endl;
                std::cout << "Would you try another game?" << std::endl << std::endl << std::endl;
                break;
            }
            }
            break;
        }

        ii++;
    }

    if (ii == 6) {
        std::cout << std::endl;
        std::cout << "Sorry, you spent all your tries. Maybe another game ?" << std::endl << std::endl << std::endl;
    }

    runWordle();
}

bool isEqual(const char* a, const char* b) {
    if (strlen(a) != strlen(b)) {
        return false;
    }
    else {
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
    }

    return true;
}

int getDay(const std::tm* tmObj)
{
    return tmObj->tm_mday;
}

int getMonth(const std::tm* tmObj)
{
    return tmObj->tm_mon + 1;
}

int getYear(const std::tm* tmObj)
{
    return tmObj->tm_year + 1900;
}