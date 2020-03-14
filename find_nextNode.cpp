#include <iostream>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* parent;
};

class findNextNode {
public:
    BinaryTreeNode* getNext(BinaryTreeNode* input) {
        // deal with the null input
        if (input == nullptr)
            return nullptr;
        
        BinaryTreeNode* pNext;
        // deal with the case where there is right subtree
        if (input->m_pRight != nullptr) {
            BinaryTreeNode* pRight = input->m_pRight;
            
            while (pRight->m_pLeft != nullptr) {
                pRight = pRight->m_pLeft;
            }

            pNext = pRight;
        } else if (input->parent != nullptr) {
            BinaryTreeNode* pCurrent = input;
            BinaryTreeNode* pParent = input->parent;

            while (pParent != nullptr && pCurrent == pParent->m_pRight) {
                pCurrent = pParent;
                pParent = pParent->parent;
            }

            pNext = pParent;
        }

        return pNext;

        // deal witht the case where there is no 
    }
};