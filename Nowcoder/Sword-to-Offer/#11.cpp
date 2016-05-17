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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> result;
        if (root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* father = q.front();
            result.push_back(father->val);
            if (father->left != NULL)
                q.push(father->left);
            if (father->right != NULL)
                q.push(father->right);
            q.pop();
        }
        return result;
    }
};
