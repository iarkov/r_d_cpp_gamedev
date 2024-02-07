#include "STL1.h"
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <stack>

bool has_cycle(Node* head) {
    std::set<Node*> setNodes;
    std::size_t setSize = setNodes.size();
    Node* testNode = head;

    while (testNode) {
        setNodes.insert(head);
        if (setSize == setNodes.size()) {
            return false;
        }
        else {
            setSize += 1;
            testNode = testNode->next;
        }
    }

    return true;
};

unsigned int uniqueWordsCount(const std::string& line) {
    std::string word = "";
    std::set<std::string> wordSet{};

    for (int i = 0; i <= line.size(); i++) {
        if (line[i] == ' ' || i == line.size()) {
            wordSet.insert(word);
            word = "";
        }
        else {
            word.push_back(line[i]);
        }
    }

    return static_cast<int>(wordSet.size());
}

std::string mostOccuredWord(const std::string& line) {
    std::string word = "";
    std::map<std::string, int> wordMap;

    for (int i = 0; i <= line.size(); i++) {
        if (line[i] == ' ' || i == line.size()) {
            wordMap[word] += 1;
            word = "";
        }
        else {
            word.push_back(line[i]);
        }
    }

    std::vector<std::pair<std::string, int>> pairVector{};
    for (std::pair<std::string, int> pair : wordMap) {
        pairVector.push_back(pair);
    }
    std::sort(pairVector.begin(), pairVector.end(), [](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2) {return p1.second > p2.second; });

    return pairVector[0].first;
}

bool areBracketsWellClosed(std::string line) {
    std::map<char, char> bracketsMap;
    bracketsMap[')'] = '(';
    bracketsMap[']'] = '[';
    bracketsMap['}'] = '{';

    std::stack<char> bracketsStack;

    for (int i = 0; i <= line.size(); i++) {
        if (line[i] == '(' || line[i] == '[' || line[i] == '{') {
            bracketsStack.push(line[i]);
        }

        if (line[i] == ')' || line[i] == ']' || line[i] == '}') {
            if (bracketsStack.top() == bracketsMap[line[i]]) {
                bracketsStack.pop();
            }
            else {
                return false;
            }
        }
    }

    return bracketsStack.empty();
}