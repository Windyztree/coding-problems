/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
 
bool compare(ListNode* n1, ListNode* n2);
 
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        vector<ListNode*> mergeNodes;
        ListNode* node1 = pHead1;
        while (node1 != NULL){
            mergeNodes.push_back(node1);
            node1 = node1->next;
        }
        ListNode* node2 = pHead2;
        while (node2 != NULL){
            mergeNodes.push_back(node2);
            node2 = node2->next;
        }
        sort(mergeNodes.begin(), mergeNodes.end(), compare);
        ListNode* newHead = mergeNodes[0];
        for (vector<ListNode*>::size_type i = 0; i < mergeNodes.size() - 1; ++i){
            mergeNodes[i]->next = mergeNodes[i + 1];
        }
        mergeNodes[mergeNodes.size() - 1]->next = NULL;
        return newHead;
    }
};
 
bool compare(ListNode* n1, ListNode* n2){
    return n1->val <= n2 -> val;
}
