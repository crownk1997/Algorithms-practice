#include <iostream>

struct treeNode {
    int key;
    treeNode* leftChild;
    treeNode* rightChild;
};

void mirrorBinaryTree(treeNode* head) {
    if (head == nullptr)
        return;
    
    if (head->leftChild == nullptr && head->rightChild == nullptr)
        return;
    
    treeNode* temp = head->leftChild;
    head->leftChild = head->rightChild;
    head->rightChild = temp;

    if (head->leftChild)
        mirrorBinaryTree(head->leftChild);
    if (head->rightChild)
        mirrorBinaryTree(head->rightChild);
}
