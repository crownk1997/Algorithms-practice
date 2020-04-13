#include <iostream>
#include <vector>

struct complexListNode {
    int key;
    complexListNode* next;
    complexListNode* sibling;
};

void cloneNodes(complexListNode* head) {
    complexListNode* node = head;
    while (node != nullptr) {
        complexListNode* cloned = new complexListNode();
        cloned->key = node->key;
        cloned->next = node->next;
        cloned->sibling = nullptr;

        node->next = cloned;

        node = cloned->next;
    }
}

void connectSiblingNodes(complexListNode* head) {
    complexListNode* node = head;
    while (node != nullptr) {
        complexListNode* cloned = node->next;
        if (node->sibling != nullptr)
            cloned->sibling = node->sibling->next;
        
        node = cloned->next;
    }
}

complexListNode* reconnectNodes(complexListNode* head) {
    complexListNode* node = head;
    complexListNode* clonedHead = nullptr;
    complexListNode* clonedNode = nullptr;

    if (node != nullptr) {
        clonedHead = clonedNode = node->next;
        node->next = clonedNode->next;
        node = node->next;
    }

    while (node != nullptr) {
        clonedNode->next = node->next;
        clonedNode = clonedNode->next;
        node->next = clonedNode->next;
        node = node->next;
    }

    return clonedHead;
}

int main() {
    return 0;
}