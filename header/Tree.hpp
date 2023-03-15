#pragma once

#include <string>

using namespace std;

struct Tree {
    int numberOfSubclasses;
    std::string nameOfClass, placeOFResidence;

    Tree *left;
    Tree *right;
};

void addNewElementToTree(const int &numberOfSubclasses, const string &nameOfClass, const string &placeOfResidence);
void printRimFromLeftToRight();
void printNodesWithTheSamePlaceOfResidence();
void printTree();
void printTheLargestBranch();
void findPlaceOfResidenceWithTheLargestNumberOfSubclasses();