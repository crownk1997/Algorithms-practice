#include <iostream>

struct BinaryTreeNode {
    int key;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
};

bool doesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool hasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
    bool result = false;

    if (pRoot1 != nullptr && pRoot2 != nullptr) {
        if (pRoot1->key == pRoot2->key)
            result = doesTree1HaveTree2(pRoot1, pRoot2);
        if(!result)
            result = hasSubTree(pRoot1->leftChild, pRoot2);
        if(!result)
            result = hasSubTree(pRoot1->rightChild, pRoot2);
    }

    return result;
}

bool doesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
    if (pRoot2 == nullptr)
        return true;
    if (pRoot1 == nullptr)
        return false;
    
    if (pRoot1->key != pRoot2->key)
        return false;
    
    return doesTree1HaveTree2(pRoot1->leftChild, pRoot2->leftChild) && doesTree1HaveTree2(pRoot1->rightChild, pRoot2->rightChild);
}