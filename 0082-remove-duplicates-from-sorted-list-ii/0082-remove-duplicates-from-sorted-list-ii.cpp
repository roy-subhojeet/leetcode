/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head && !head->next) return head;
        ListNode* newList = new ListNode(-1);
        ListNode* curr = newList;
        while(head && head->next)
        {
            if(head->val != head->next->val)
            {
                curr->next = head;
                curr = curr->next;
                head = head->next;
            }
            else
            {
                while(head && head->next && head->val == head->next->val)
                {
                    head = head->next;
                }
                curr->next = head->next;
                head = head->next;
            }

        }
        head = newList->next;
        delete newList;
        return head;
        
    }
};