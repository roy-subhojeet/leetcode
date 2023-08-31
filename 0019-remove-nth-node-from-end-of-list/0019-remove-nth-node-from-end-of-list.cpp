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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(!head || !head->next) return nullptr;

        int i = 1;

        ListNode* next = head;
        ListNode* prev = nullptr;
        ListNode* final = head;

        while(i < n)
        {
            next = next->next;
            ++i;
        }

        if(!next->next) return head->next;

        while(next->next)
        {
            if(!prev) prev = head;
            else prev = prev->next;
            head = head->next;
            next = next->next;
        }

        if(prev) prev->next = head->next;

        return final;
    }
};