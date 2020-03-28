#include <iostream>

struct ListNode {
    int key;
    ListNode* pNext;
};

ListNode* MeetingNode(ListNode* pHead) {
    if (pHead == nullptr)
        return nullptr;
    
    ListNode* pSlow = pHead->pNext;
    if (pSlow == nullptr)
        return nullptr;
    
    ListNode* pFast = pSlow->pNext;
    
    while (pFast != nullptr && pSlow != nullptr) {
        if (pFast == pSlow)
            return pFast;
        
        pFast = pFast->pNext;
        pSlow = pSlow->pNext;
        if (pFast != nullptr)
            pFast = pFast->pNext;
    }

    return nullptr;
}

ListNode* entryNodeOfRing(ListNode* head) {
    ListNode* meetingNode = MeetingNode(head);
    if (meetingNode == nullptr)
        return nullptr;
    
    int nodeInLoop = 1;
    ListNode* pNode1 = meetingNode;
    while (pNode1->pNext != meetingNode) {
        pNode1 = pNode1->pNext;
        nodeInLoop++;
    }

    ListNode* entryNode = head;
    for (int i = 0; i < nodeInLoop; i++) {
        entryNode = entryNode->pNext;
    }

    ListNode* pNode2 = head;
    while (pNode2 != entryNode) {
        pNode2 = pNode2->pNext;
        entryNode = entryNode->pNext;
    }

    return entryNode;
}

int main() {
    ListNode* head = new ListNode();
    ListNode* temp = head;
    for (int i = 0; i < 8; i++) {
        temp->key = i;
        temp->pNext = new ListNode();
    }
    temp->key = 8;
    temp->pNext = head->pNext->pNext;

    ListNode* entry = entryNodeOfRing(head);
    if (entry != nullptr)
        std::cout << entry->key << std::endl;

    return 0;
}