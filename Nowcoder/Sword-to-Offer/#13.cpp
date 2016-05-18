/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if (pRoot == NULL)
            return result;
        stack<TreeNode*> s1, s2;
        s1.push(pRoot);
        while (!s1.empty()){
            vector<int> oneLayer;
            while (!s1.empty()){
                TreeNode* father = s1.top();
                oneLayer.push_back(father->val);
                cout << "1" << " " << father->val << endl;
                if (father->left != NULL)
                    s2.push(father->left);
                if (father->right != NULL)
                    s2.push(father->right);
                s1.pop();
            }
            result.push_back(oneLayer);
            if (s2.empty())
                return result;
            vector<int> oneLayer1;
            while (!s2.empty()){
                TreeNode* father = s2.top();
                oneLayer1.push_back(father->val);
                cout << "2" << " " << father->val << endl;
                if (father->right != NULL)
                    s1.push(father->right);
                if (father->left != NULL)
                    s1.push(father->left);
                s2.pop();
            }
            result.push_back(oneLayer1);
        }
        return result;
    }
};
