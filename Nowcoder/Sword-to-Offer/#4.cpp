/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return NULL;
		ListNode* slow = pHead->next;
        ListNode* fast = slow->next;
        if (fast == NULL)
            return NULL;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL)
                return NULL;
            if (slow != fast)
                fast = fast->next;
            if (fast == NULL)
                return NULL;
        }
        ListNode* meetNode = fast;
        int loopLength = 1;
        while (fast->next != meetNode){
            loopLength++;
            fast = fast->next;
        }
        ListNode* front = pHead;
        for (int i = 0; i < loopLength; ++i)
            front = front->next;
        ListNode* back = pHead;
        while (back != front){
            front = front->next;
            back = back->next;
        }
        return front;
    }
};
