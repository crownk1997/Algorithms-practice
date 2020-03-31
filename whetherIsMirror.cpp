#include <iostream>
#include <vector>
#define NIL -1

struct treeNode {
    int key;
    treeNode* leftChild;
    treeNode* rightChild;
};

void traversePreorder(treeNode* head, std::vector<int>& keys) {
    if (head == nullptr) {
        keys.push_back(NIL);
        return;
    }

    traversePreorder(head->leftChild, keys);
    keys.push_back(head->key);
    traversePreorder(head->rightChild, keys);
}

void traverseAfterorder(treeNode* head, std::vector<int>& keys) {
    if (head == nullptr) {
        keys.push_back(NIL);
        return;
    }

    traverseAfterorder(head->rightChild, keys);
    keys.push_back(head->key);
    traverseAfterorder(head->leftChild, keys);
}

bool whetherIsMirror(treeNode* head) {
    std::vector<int> preorder_key;
    std::vector<int> aftorder_key;

    traversePreorder(head, preorder_key);
    traverseAfterorder(head, aftorder_key);

    int size1 = preorder_key.size();
    int size2 = aftorder_key.size();

    if (size1 != size2)
        return false;
    
    for (int i = 0; i < size1; i++) {
        if (preorder_key[i] != aftorder_key[i])
            return false;
    }

    return true;
}

int main() {
    return 0;
}