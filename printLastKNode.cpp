#include <iostream>
#include <cassert>

struct ListNode {
    int key;
    ListNode* pNext;
};

void printLastKNode(ListNode* head, int k) {
    assert (k >= 1);
    if (head == nullptr) {
        return;
    }

    ListNode* pointer1 = head;
    ListNode* pointer2 = head;
    for (int i = 0; i < k-1; i++) {
        if (pointer1->pNext != nullptr) {
            pointer1 = pointer1->pNext;
        } else {
            return;
        }
    }

    while (pointer1->pNext != nullptr) {
        pointer1 = pointer1->pNext;
        pointer2 = pointer2->pNext;
    }

    std::cout << pointer2->key << std::endl;
}

int main() {
    return 0;
}
