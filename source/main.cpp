#include <iostream>

using namespace std;

enum class Option {
    ADD_ELEMENT = 1,
    PRINT_RIM_FROM_LEFT_TO_RIGHT,
    PRINT_NODES_WITH_SIMILAR_PLACE_OF_RESIDENCE,
    FIND_PLACE_WHERE_THE_LARGEST_NUMBER_OF_CLASSES_AND_SUBCLASSES,
    PRINT_THE_LARGEST_BRANCH,
    PRINT_TREE,
    EXIT
};

void instruction() {
    cout << "1 - add element to the tree" << endl
         << "2 - print rim from left to right" << endl
         << "3 - print nodes with the similar place of residence" << endl
         << "4 - finding the place of residence where the largest number of classes and subclasses is located" << endl
         << "5 - print the largest branch" << endl
         << "6 - print the entire tree" << endl
         << "7 - exit" << endl;
}

Option getOption() {
    int choice{};
    cout << "Your choice: ";
    cin >> choice;
    return static_cast<Option>(choice);
}

int main() {
    Option option{};

    do  {
        option = getOption();
        
        switch (option) {
        case Option::ADD_ELEMENT:
            break;
        
        case Option::PRINT_RIM_FROM_LEFT_TO_RIGHT:
            break;

        case Option::PRINT_NODES_WITH_SIMILAR_PLACE_OF_RESIDENCE:
            break;
        
        case Option::FIND_PLACE_WHERE_THE_LARGEST_NUMBER_OF_CLASSES_AND_SUBCLASSES:
            break;
        
        case Option::PRINT_THE_LARGEST_BRANCH:
            break;

        case Option::PRINT_TREE:
            break;

        default:
            break;
        }
    } while (option != Option::EXIT);
    
}