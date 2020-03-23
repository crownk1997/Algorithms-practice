#include <iostream>
#include <vector>

struct ListNode {
    int m_nvalue;
    ListNode* m_pNext;
};

void deleteNode(ListNode* root, ListNode* toBeDeleted) {
    if (root == nullptr || toBeDeleted == nullptr)
        return;
    
    if (toBeDeleted->m_pNext != nullptr) {
        ListNode* next = toBeDeleted->m_pNext;
        toBeDeleted->m_nvalue = next->m_nvalue;
        toBeDeleted->m_pNext = next->m_pNext;
    } else if(root == toBeDeleted) {
        delete toBeDeleted;
        toBeDeleted = nullptr;
        root = nullptr; 
    } else {
        ListNode* pNode = root;
        while (pNode->m_pNext != toBeDeleted) {
            pNode = pNode->m_pNext;
        }

        pNode->m_pNext = nullptr;
        delete toBeDeleted;
        toBeDeleted = nullptr;
    }
}

void printList(ListNode* root) {
    if (root == nullptr)
        return;

    ListNode* temp = root;
    while (temp->m_pNext != nullptr) {
        std::cout << temp->m_nvalue << "\n";
        temp = temp->m_pNext;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode;
    ListNode* temp = head;

    for (int i = 0; i < 5; i++) {
        ListNode* next = new ListNode;
        temp->m_nvalue = i;
        temp->m_pNext = next;
        temp = temp->m_pNext;
    }
    temp->m_nvalue = 5;
    temp->m_pNext = nullptr;

    printList(head);

    ListNode* nodeToBeDeleted = head->m_pNext->m_pNext;
    deleteNode(head, nodeToBeDeleted);

    printList(head);

    return 0;
}