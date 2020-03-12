
// Print the invser link

#include <iostream>
#include <stack>
#include <vector>

struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
};

class printInv {
private:
    std::stack<int> result;
public:
    void solution(ListNode* root) {
        if (root == NULL)
            return;
        
        ListNode* curr = root;
        while (curr != NULL) {
            result.push(curr->m_nKey);
            curr = curr->m_pNext;
        }

        while (!result.empty()) {
            std::cout << result.top() << " ";
            result.pop();
        }

        std::cout << std::endl;
    }
};

int main(int argc, char** argv) {
    ListNode* root = new ListNode[5];
    ListNode* cur = root;
    for (int i = 0; i < 5; i++) {
        cur->m_nKey = i;
        if (i < 4) {
            cur->m_pNext = &root[i+1];
            cur = cur->m_pNext;
        }
    }

    printInv solve;
    solve.solution(root);
    delete [] root;

    return 0;
}