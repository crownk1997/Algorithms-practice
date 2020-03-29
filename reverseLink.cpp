#include <iostream>

struct ListNode {
    int key;
    ListNode* p_Next;
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr)
        return nullptr;
    
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
        ListNode* next = cur->p_Next;
        cur->p_Next = prev;

        prev = cur;
        cur = next;
    }
    return prev;
}

void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        std::cout << cur->key << " ";
        cur = cur->p_Next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode();
    ListNode* cur = head;
    for (int i = 0; i < 8; i++) {
        cur->key = i;
        cur->p_Next = new ListNode();
        cur = cur->p_Next;
    }
    cur->p_Next = nullptr;
    cur->key = 9;

    printList(head);
    ListNode* new_head = reverseList(head);
    printList(new_head);

    return 0;
}