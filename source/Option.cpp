#include "Option.hpp"

void instruction() {
    std::cout << "\n1 - add element to the tree" << std::endl
              << "2 - print rim from left to right" << std::endl
              << "3 - print nodes with the similar place of residence" << std::endl
              << "4 - finding the place of residence where the largest number of classes and subclasses is located" << std::endl
              << "5 - print the largest branch" << std::endl
              << "6 - print the entire tree" << std::endl
              << "7 - exit" << std::endl;
}

Option getOption() {
    int choice{};
    std::cout << "Your choice: ";
    std::cin >> choice;
    return static_cast<Option>(choice);
}