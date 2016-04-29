using namespace std;
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL)
            return NULL;
        if (pNode->next == NULL){
            if (pNode->right == NULL)
                return NULL;
            else{
                TreeLinkNode* leftChild = pNode->right;
                while ((leftChild->left) != NULL)
                    leftChild = leftChild->left;
                return leftChild;
            }
        }
        if (pNode->right == NULL){
            if (pNode->next->left == pNode)
                return pNode->next;
            else{
                TreeLinkNode* father = pNode->next;
                while (father != NULL){
                    if (father->next == NULL)
                        return NULL;
                    if (father->next->left == father)
                        return father->next;
                    father = father->next;
                }
                return father;
            }
        }
        else{
            TreeLinkNode* leftChild = pNode->right;
            while ((leftChild->left) != NULL)
                leftChild = leftChild->left;
            return leftChild;
        }
    }
};
