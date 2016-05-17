/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return pRootOfTree;
        if (pRootOfTree->left != NULL){
            TreeNode* leftChild = Convert(pRootOfTree->left);
            while (leftChild->right != NULL)
                leftChild = leftChild->right;
            leftChild->right = pRootOfTree;
            pRootOfTree->left = leftChild;
        }
        if (pRootOfTree->right != NULL){
            TreeNode* rightChild = Convert(pRootOfTree->right);
            while (rightChild->left != NULL)
                rightChild = rightChild->left;
            rightChild->left = pRootOfTree;
            pRootOfTree->right = rightChild;
        }
        while (pRootOfTree->left != NULL)
            pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }
};
