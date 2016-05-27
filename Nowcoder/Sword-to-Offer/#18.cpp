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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root != NULL)
        	formPath(root, expectNumber);
		return allPaths;
    }

    void formPath(TreeNode* root, int expectNumber){
        if ((root->val == expectNumber) && (root->left == NULL) && (root->right == NULL)){
            onePath.push_back(root->val);
            allPaths.push_back(onePath);
            onePath.pop_back();
        }
        else if (root->val < expectNumber){
            onePath.push_back(root->val);
            int newExpectedNumber = expectNumber - (root->val);
            if (root->left)
                formPath(root->left, newExpectedNumber);
            if (root->right)
                formPath(root->right, newExpectedNumber);
            onePath.pop_back();
        }
    }
private:
    vector<vector<int> > allPaths;
    vector<int> onePath;
};
