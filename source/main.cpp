#include <iostream>
#include "Tree.hpp"
#include "Option.hpp"

using namespace std;

int main() {
    Option option{};
    Tree *root{nullptr};
    Data data{};
    do  {
        instruction();
        option = getOption();
        
        switch (option) {
        case Option::ADD_ELEMENT:
            data = fillData();
            addNewElementToTree(root, data);
            break;
        
        case Option::PRINT_FROM_LEFT_TO_RIGHT:
            if(root != nullptr) {
                printArticle();
                printFromLeftToRight(root);
            }
            else std::cout << "The tree is empty" << std::endl;
            break;

        case Option::PRINT_NODES_WITH_SIMILAR_PLACE_OF_RESIDENCE:
            break;
        
        case Option::FIND_PLACE_WHERE_THE_LARGEST_NUMBER_OF_CLASSES_AND_SUBCLASSES:
            break;
        
        case Option::PRINT_THE_LARGEST_BRANCH:
            break;

        case Option::PRINT_TREE:
            if(root != nullptr) {
                printArticle();
                printTree(root);
            }
            else std::cout << "The tree is empty" << std::endl;
            break;
            
        case Option::EXIT:
            break;

        default:
            std::cout << "Incorrect option." << std::endl;
            break;
        }
    } while (option != Option::EXIT);
}