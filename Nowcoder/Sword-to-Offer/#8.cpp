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
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        stack<ListNode*> transfer;
        ListNode* pointer = pHead;
        while (pointer != NULL){
            transfer.push(pointer);
            pointer = pointer->next;
        }
        ListNode* reverseHead = transfer.top();
        ListNode* reversePointer = reverseHead;
        transfer.pop();
        while (!transfer.empty()){
            reversePointer->next = transfer.top();
            transfer.pop();
            reversePointer = reversePointer->next;
        }
        reversePointer->next = NULL;
        return reverseHead;
    }
};
