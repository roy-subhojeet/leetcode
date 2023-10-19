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
    ListNode* removeElements(ListNode* head, int val) {

        while(head && head->val == val) head = head->next;
        if(!head) return nullptr;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr)
        {
            ListNode *temp = curr->next;
            if(curr->val == val)
            {
                prev->next = temp;
            }
            else prev = curr;
            curr = temp;
        }
        return head;
        
    }
};