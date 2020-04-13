#include <iostream>
#include <vector>

struct BinaryNode {
    int key;
    BinaryNode* leftChild;
    BinaryNode* rightChild;
};

void convertNode(BinaryNode* node, BinaryNode* lastNodeInList) {
    if (node == nullptr)
        return;
    
    BinaryNode* current = node;
    if (current->leftChild)
        convertNode(current->leftChild, lastNodeInList);
    
    current->leftChild = lastNodeInList;
    if (lastNodeInList)
        lastNodeInList->rightChild = current;
    
    lastNodeInList = current;

    if (current->rightChild)
        convertNode(current->righChild, lastNodeInList);
}

BinaryNode* convert(BinaryNode* root) {
    if (root == nullptr)
        return nullptr;
    
    BinaryNode* lastNodeInList = nullptr;
    convertNode(root, lastNodeInList);

    BinaryNode* headOfList = nullptr;
    while (headOfList != nullptr && headOfList->leftChild != nullptr)
        headOfList = headOfList->leftChild;
    
    return headOfList;
}

int main() {
    return 0;
}