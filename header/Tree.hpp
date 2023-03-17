#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;
struct Data{
    int numberOfSubclasses;
    std::string nameOfClass, placeOFResidence;
};
struct Tree {
    Data data;
    Tree *left;
    Tree *right;
};

Data fillData();
void addNewElementToTree(Tree *&root, const Data& d);
void printFromLeftToRight(Tree *root);
void printNodesWithTheSamePlaceOfResidence(Tree *&root);
void printTree(Tree *&root);
int printTheLargestBranch(Tree *&root);
void findPlaceOfResidenceWithTheLargestNumberOfSubclasses(Tree *&root);
string toLowerCase(const string &s);
bool compareTwoStrings(const string &first, const string &second);
size_t getSmallerSizeOfStrings(const string &f, const string &s);
void createElementOfTree(Tree *&element, const Data &d);
void printElementOfTree(Tree *&element);
void printPictureOfTree(Tree *&root, int space);