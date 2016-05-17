/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
 
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* newHead = NULL;
        ListNode* newNode;
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        while (pHead1 != NULL && pHead2 != NULL){
            if (pHead1->val <= pHead2->val){
                if (newHead == NULL)
                    newHead = newNode = pHead1;
                else{
                    newNode->next = pHead1;
                    newNode = newNode->next;
                }
                pHead1 = pHead1->next;
            }
            else{
                if (newHead == NULL)
                    newHead = newNode = pHead2;
                else{
                    newNode->next = pHead2;
                    newNode = newNode->next;
                }
                pHead2 = pHead2->next;
            }
        }
        if (pHead1 == NULL)
            newNode->next = pHead2;
        else if (pHead2 == NULL)
            newNode->next = pHead1;
        return newHead;
    }
};
