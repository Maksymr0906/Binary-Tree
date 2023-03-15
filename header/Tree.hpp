#pragma once

#include <string>

using namespace std;

struct Tree {
    int numberOfClasses, numberOfSubclasses;
    std::string placeOFResidence;

    Tree *brother;
    Tree *son;
};