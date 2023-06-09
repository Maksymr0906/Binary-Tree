#include "Option.hpp"

void instruction() {
    std::cout << "\n1 - add element to the tree" << std::endl
              << "2 - print from left to right" << std::endl
              << "3 - print nodes with the similar place of residence" << std::endl
              << "4 - finding node where the largest number of classes and subclasses is located" << std::endl
              << "5 - print the largest branch" << std::endl
              << "6 - print the entire tree" << std::endl
              << "7 - print the picture of tree" << std::endl
              << "8 - exit" << std::endl;
}

Option getOption() {
    int choice{};
    std::cout << "Your choice: ";
    std::cin >> choice;
    return static_cast<Option>(choice);
}

void printArticle() {
    std::cout << std::setw(25) << "Name of Class" 
              << std::setw(25) << "Place of Residence" 
              << std::setw(25) << "Number of Subclasess" << std::endl;
}