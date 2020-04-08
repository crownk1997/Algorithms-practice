#include <iostream>
#include <stack>

struct Node {
    int key;
    Node* leftChild;
    Node* rightChild;
};

void printBinaryTree(Node* head) {
    if (head == nullptr)
        return;
    
    std::stack<Node*> levels[2];
    int current = 0;
    int next = 1;

    while (!levels[0].empty() || !levels[1].empty()) {
        Node* pNode = levels[current].top();
        levels[current].pop();

        cout << pNode->key;

        if (current == 0) {
            if (pNode->leftChild)
                levels[next].push(pNode->leftChild);
            if (pNode->rightChild)
                levels[next].push(pNode->rightChild);
        } else {
            if (pNode->rightChild)
                levels[next].push(pNode->rightChild);
            if (pNode->leftChild)
                levels[next].push(pNode->leftChild);\
        }

        if (levels[current].empty()) {
            current = 1 - current;
            next = 1 - next;
            cout << endl;
        }
    }
}

int main () {
    return 0;
}