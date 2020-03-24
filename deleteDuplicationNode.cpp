#include <iostream>

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
};

void deleteDuplication(ListNode* head) {
    if (head == nullptr || head->m_pNext == nullptr)
        return;
    
    ListNode* pPreNode = nullptr;
    ListNode* pNode = head;
    while (pNode != nullptr) {
        ListNode* pNext = pNode->m_pNext;
        bool needDelete = false;
        if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;

        if (!needDelete) {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        } else {
            int value = pNode->m_nValue;
            ListNode* pToBeDel = pNode;
            while (pToBeDel != nullptr && pToBeDel->m_nValue == value) {
                pNext = pToBeDel->m_pNext;

                delete pToBeDel;
                pToBeDel = pNext; 
            }
        }
    }
}
