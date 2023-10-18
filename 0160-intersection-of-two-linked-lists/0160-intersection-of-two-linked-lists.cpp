/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int nA = 0;
        int nB = 0;
        ListNode* curr = headA;
        while(curr)
        {
            curr = curr->next;
            ++nA;
        }
        curr = headB;
        while(curr)
        {
            curr = curr->next;
            ++nB;
        }

        curr = nA >= nB ? headA : headB;
        ListNode* other = nA < nB ? headA : headB; 

        int toSkip = abs(nA - nB);
        while(toSkip != 0)
        {
            curr = curr->next;
            --toSkip;
        }
        while(curr)
        {
            if(curr == other) return curr;
            other = other->next;
            curr = curr->next;
        }
        return nullptr;

        
    }
};