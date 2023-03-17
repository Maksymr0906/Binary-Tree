#pragma once

#include <iostream>
#include <iomanip>

enum class Option {
    ADD_ELEMENT = 1,
    PRINT_FROM_LEFT_TO_RIGHT,
    PRINT_NODES_WITH_SIMILAR_PLACE_OF_RESIDENCE,
    FIND_NODE_WHERE_THE_LARGEST_NUMBER_OF_CLASSES_AND_SUBCLASSES,
    PRINT_THE_LARGEST_BRANCH,
    PRINT_TREE,
    PRINT_PICTURE_OF_TREE,
    EXIT
};

void instruction();
Option getOption();
void printArticle();