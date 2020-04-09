#include <iostream>
#include <vector>

using namespace std;

struct BinaryNode {
    int key;
    BinaryNode* leftChild;
    BinaryNode* rightChild;
};

bool verifySquenceOfBST(const vector<int>& seq, int start, int index) {
    if (seq.empty())
        return false;
    
    int length = index;
    int root = seq[length-1];
    int i;
    for (i = 0; i < length - 1; i++) {
        if (seq[i] > root)
            break;
    }

    for (int j = i; j < length - 1; j++) {
        if (seq[j] < root)
            return false;
    }

    bool left = true;
    if (i > 0)
        left = verifySquenceOfBST(seq, 0, i);
    
    bool right = true;
    if (i < length - 1)
        right = verifySquenceOfBST(seq, i, length - i - 1);

    return left && right;
}

int main() {
    vector<int> seq = {5, 7, 6, 9, 11, 10, 8};
    cout << "If the seq is binary tree: " << verifySquenceOfBST(seq, 0, seq.size()) << endl;

    return 0;    
}