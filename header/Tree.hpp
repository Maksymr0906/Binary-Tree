#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

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
void printBiggestBranch(Tree *root);
void printBiggestBranchHelper(Tree *root, std::vector<Data>& biggestBranch);
Tree* findNodeWithTheLargestNumberOfSubclasses(Tree *root);
string toLowerCase(const string &s);
bool compareTwoStrings(const string &first, const string &second);
size_t getSmallerSizeOfStrings(const string &f, const string &s);
void createElementOfTree(Tree *&element, const Data &d);
void printElementOfTree(Data &data);
void printPictureOfTree(Tree *&root, int space);