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
            return true;
        }
        else if(firstString[i] == secondString[i]) {
            continue;
        }
        else if(firstString[i] != secondString[i]) {
            return false;
        }
    }

    return false;
}


Data fillData() {
    Data d;

    std::cin.ignore();
    std::cout << "Enter the name of class: ";
    getline(cin, d.nameOfClass);

    std::cout << "Enter the place of residence: ";
    getline(cin, d.placeOfResidence);

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

void printElementOfTree(Data &data) {
    std::cout << std::setw(25) << data.nameOfClass
              << std::setw(25) << data.placeOfResidence
              << std::setw(25) << data.numberOfSubclasses << std::endl;
}

void addNewElementToTree(Tree *&root, const Data &d) {
    if(root == nullptr) {
        createElementOfTree(root, d);
        return ;
    }

    if(compareTwoStrings(root->data.nameOfClass, d.nameOfClass)) {
        addNewElementToTree(root->right, d);
    }
    else {
        addNewElementToTree(root->left, d);
    }
}

void printTree(Tree *root) {
    if(root == nullptr) {
        return ;
    }

    printTree(root->left);
    printElementOfTree(root->data);
    printTree(root->right);
}

void printFromLeftToRight(Tree *root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Tree*> q;
    q.push(root);

    while (!q.empty()) {
        Tree *current = q.front();
        q.pop();

        printElementOfTree(current->data);

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void printPictureOfTree(Tree *root, int space) {
     if(root == nullptr) {
        return ;
    }

    space+=10;
    printPictureOfTree(root->right, space);

    cout << endl;
    for (size_t i = 10; i < space; i++) {
        cout << " ";
    }
    
    cout << root->data.nameOfClass << endl;
    printPictureOfTree(root->left, space);
}

void printBiggestBranchHelper(Tree *root, std::vector<Data>& biggestBranch) {
    if (root == nullptr) {
        return;
    }

    std::vector<Data> leftBranch, rightBranch;
    printBiggestBranchHelper(root->left, leftBranch);
    printBiggestBranchHelper(root->right, rightBranch);

    if (leftBranch.size() >= rightBranch.size()) {
        leftBranch.push_back(root->data);
        biggestBranch = leftBranch;
    } else {
        rightBranch.push_back(root->data);
        biggestBranch = rightBranch;
    }
}

void printBiggestBranch(Tree *root) {
    if (root == nullptr) {
        return;
    }

    std::vector<Data> biggestBranch;
    printBiggestBranchHelper(root, biggestBranch);

    for (auto& data : biggestBranch) {
        printElementOfTree(data);
    }
}

Tree* findNodeWithTheLargestNumberOfSubclasses(Tree *root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    Tree *maxNode = root;
    if (root->left != nullptr) {
        Tree *leftMax = findNodeWithTheLargestNumberOfSubclasses(root->left);
        if (leftMax->data.numberOfSubclasses > maxNode->data.numberOfSubclasses) {
            maxNode = leftMax;
        }
    }
    if (root->right != nullptr) {
        Tree *rightMax = findNodeWithTheLargestNumberOfSubclasses(root->right);
        if (rightMax->data.numberOfSubclasses > maxNode->data.numberOfSubclasses) {
            maxNode = rightMax;
        }
    }
    return maxNode;
}

bool isPlaceOfResidenceExistInVector(const std::string &placeOfResidence, const vector<string> &placesOfResidence) {
    for (const auto& place : placesOfResidence) {
        if (placeOfResidence == place)
            return true;
    }
    return false;
}

void fillVectorWithPlacesOfResidence(Tree* root, vector<string> &placesOfResidence) {
    if (root == nullptr) {
        return ;
    }

    if (!isPlaceOfResidenceExistInVector(root->data.placeOfResidence, placesOfResidence)) {
        placesOfResidence.push_back(root->data.placeOfResidence);
    }

    fillVectorWithPlacesOfResidence(root->left, placesOfResidence);
    fillVectorWithPlacesOfResidence(root->right, placesOfResidence);
}

void printNodesWithSamePlaceOfResidence(Tree *root, const string& placeOfResidence) {
    if (root == nullptr) {
        return ;
    }

    if (root->data.placeOfResidence == placeOfResidence) {
        printElementOfTree(root->data);
    }

    printNodesWithSamePlaceOfResidence(root->left, placeOfResidence);
    printNodesWithSamePlaceOfResidence(root->right, placeOfResidence);
}

void countNodesWithSamePlaceOfResidence(Tree *root, const string &placeOfResidence, int &counter) {
    if(root == nullptr) {
        return ;
    }

    if(root->data.placeOfResidence == placeOfResidence) {
        counter++;
    }

    countNodesWithSamePlaceOfResidence(root->left, placeOfResidence, counter);
    countNodesWithSamePlaceOfResidence(root->right, placeOfResidence, counter);
}

void findNodesWithSamePlaceOfResidence(Tree *root) {
    vector<string> placesOfResidence;
    fillVectorWithPlacesOfResidence(root, placesOfResidence);

    for (const auto& placeOfResidence : placesOfResidence) {
        int counter = 0;
        countNodesWithSamePlaceOfResidence(root, placeOfResidence, counter);


        if (counter >= 2) {
            std::cout << "Nodes with place of residence " << placeOfResidence << ":" << std::endl;
            printNodesWithSamePlaceOfResidence(root, placeOfResidence);
            std::cout << std::endl;
        }
    }
}