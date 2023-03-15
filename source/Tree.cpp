#include "Tree.hpp"

size_t getSmallerSizeOfStrings(const string &f, const string &s) {
    return f.size() < s.size()? f.size(): s.size();
}

string toLowerCase(const string &s) {
    string result{};
    for (size_t i = 0; i < s.size(); i++)   {
        result += tolower(s[i]);
    }

    return result;
}

bool compareTwoStrings(const string &first, const string &second) {
    string firstString = toLowerCase(first), secondString = toLowerCase(second);
    size_t size = getSmallerSizeOfStrings(first, second);    
    
    for (size_t i = 0; i < size; i++)   {
        if(firstString[i] < secondString[i]) {
            return 1;
        }
    }

    return 0;
}


Data fillData() {
    Data d;

    std::cin.ignore();
    std::cout << "Enter the name of class: ";
    getline(cin, d.nameOfClass);

    std::cout << "Enter the place of residence: ";
    getline(cin, d.placeOFResidence);

    std::cout << "Enter the number of subclasses: ";
    std::cin >> d.numberOfSubclasses;

    return d;
}

void createElementOfTree(Tree *&element, const Data &d) {
    element = new Tree();
    element->data = d;
    element->left = nullptr;
    element->right = nullptr;
}

void addNewElementToTree(Tree *&root, const Data &d) {
    if(root == nullptr) {
        createElementOfTree(root, d);
        return ;
    }

    if(compareTwoStrings(root->data.nameOfClass, d.nameOfClass)) {
        addNewElementToTree(root->right, d);
    }
    else if(root->left == nullptr) {
        addNewElementToTree(root->left, d);
    }
}

void printTree(Tree *&root, int space) {
    if(root == nullptr) {
        return ;
    }

    space+=10;
    printTree(root->right, space);

    cout << endl;
    for (size_t i = 10; i < space; i++) {
        cout << " ";
    }
    
    cout << root->data.nameOfClass << endl;
    printTree(root->left, space);
}