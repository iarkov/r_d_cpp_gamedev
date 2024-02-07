#include <iostream>
#include "STL1.h"


int main()
{
    std::string s = "Hello Hey Hello Bye Hey";
    std::cout << "String \"" << s << "\" has " << uniqueWordsCount(s) << " unique words." << std::endl << std::endl;
    std::cout << "The most frequent word in string \"" << s << "\" is \"" << mostOccuredWord(s) << "\"." << std::endl << std::endl;
    
    std::string allBracketsClosed = "{[(wowowo)wowow]oyoyo[lolo]}";
    std::string bracketsNotProperlyClosed = "{[}]()";
    std::string bracketsNotClosed = "{()[]";

    std::cout << areBracketsWellClosed(allBracketsClosed) << " "
        << areBracketsWellClosed(bracketsNotProperlyClosed) << " "
        << areBracketsWellClosed(bracketsNotClosed) << std::endl << std::endl;

    LinkedList linkedList;
    linkedList.push_front(1);
    linkedList.push_front(2);
    linkedList.push_front(3);
    std::cout << has_cycle(linkedList.getHead());
}
