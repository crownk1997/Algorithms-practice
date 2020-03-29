#include <iostream>

struct ListNode {
    int key;
    ListNode* p_Next;
};


void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        std::cout << cur->key << " ";
        cur = cur->p_Next;
    }
    std::cout << std::endl;
}

ListNode* mergeTwoSortList(ListNode* head1, ListNode* head2) {
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;
    
    ListNode* new_head;
    if (head1->key >= head2->key) {
        new_head =head2;
        new_head->p_Next = mergeTwoSortList(head1, head2->p_Next);
    } else{
        new_head =head1;
        new_head->p_Next = mergeTwoSortList(head1->p_Next, head2);
    }

    return new_head;
}

int main() {
    ListNode* head1 = new ListNode();
    ListNode* cur = head1;
    for (int i = 0; i < 8; i+=2) {
        cur->key = i;
        cur->p_Next = new ListNode();
        cur = cur->p_Next;
    }

    cur->p_Next = nullptr;
    cur->key = 8;

    ListNode* head2 = new ListNode();
    cur = head2;
    for (int i = 1; i < 9; i+=2) {
        cur->key = i;
        cur->p_Next = new ListNode();
        cur = cur->p_Next;
    }
    cur->p_Next = nullptr;
    cur->key = 9;

    printList(head1);
    printList(head2);

    ListNode* mergeHead = mergeTwoSortList(head1, head2);
    printList(mergeHead);

    return 0;
}