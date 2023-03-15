#pragma once

#include <iostream>

enum class Option {
    ADD_ELEMENT = 1,
    PRINT_RIM_FROM_LEFT_TO_RIGHT,
    PRINT_NODES_WITH_SIMILAR_PLACE_OF_RESIDENCE,
    FIND_PLACE_WHERE_THE_LARGEST_NUMBER_OF_CLASSES_AND_SUBCLASSES,
    PRINT_THE_LARGEST_BRANCH,
    PRINT_TREE,
    EXIT
};

void instruction();
Option getOption();