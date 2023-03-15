#include <iostream>
#include "Tree.hpp"
#include "Option.hpp"

using namespace std;

Tree *root;

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