#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compareByLength(const std::string& s1, const std::string& s2) {
    return s1.size() > s2.size();
}

class CompareByLength {
public:
    CompareByLength() {}

    bool operator()(const std::string& s1, const std::string& s2) { return s1.size() > s2.size(); }
};

auto lambdaCompareByLength = [](const std::string& s1, const std::string& s2) { return s1.size() > s2.size(); };

int countDivisibleBy(const std::vector<int>& vec, int number) {
    return std::count_if(vec.begin(), vec.end(), [number](int a) { return a% number == 0; });
}

int main()
{
    std::vector<std::string> stringContainer{ "very", "random", "string" };

    //std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
    //CompareByLength c; 
    //std::sort(stringContainer.begin(), stringContainer.end(), c);
    std::sort(stringContainer.begin(), stringContainer.end(), lambdaCompareByLength);

    for (std::string s : stringContainer) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::vector<int> intVector{ 1,2,3,4,5,6 };
    int divisibleBy3 = countDivisibleBy(intVector, 3);
    std::cout << divisibleBy3;
}