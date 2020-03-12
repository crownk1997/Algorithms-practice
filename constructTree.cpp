
// construct binary tree based on traversal on repated value

#include <vector>
#include <exception>
#include <stdexcept>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

class constructTree {
private:
    BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, 
                                int* startInorder, int* endInorder) {
        int rootValue = startPreorder[0];
        BinaryTreeNode* root = new BinaryTreeNode();
        root->m_nValue = rootValue;
        root->m_pLeft = root->m_pRight = nullptr;

        // if we only have one value, this value should be equal
        if (startPreorder == endPreorder) {
            if (startInorder == endInorder && *startPreorder == *startInorder)
                return root;
            else {
                throw std::runtime_error("Invalid input");
            }
        }

        // search the root value in the inorder array
        int* rootInorder = startInorder;
        while (rootInorder <= endInorder && *rootInorder != rootValue) 
            ++rootInorder;
        
        if (rootInorder == endInorder && *rootInorder != rootValue) {
            throw std::runtime_error("Cannot find the corresponding root value");
        }

        int leftLength = rootInorder - startInorder;
        int* leftPreorderEnd = startPreorder + leftLength;
        if (leftLength > 0) {
            root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder - 1);
        }
        if (leftLength < endPreorder - startPreorder) {
            root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
        }

        return root;
    }
public:
    BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
        if (preorder == nullptr || inorder == nullptr || length <= 0)
            return nullptr;
        
        return ConstructCore(preorder, preorder + length - 1, 
        inorder, inorder + length - 1);
    }
};


int main(int argc, char** argv) {
    int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};

    constructTree solve;
    BinaryTreeNode* root = solve.Construct(preorder, inorder, 8);

    return 0;
}
