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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* reverseHead = NULL;
        ListNode* p = pHead;
        while (p != NULL){
            ListNode* next = p->next;
            p->next = reverseHead;
            reverseHead = p;
            p = next;
        }
        return reverseHead;
    }
};
