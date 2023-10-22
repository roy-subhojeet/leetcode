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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* newHead = head->next;  // This will be our new head after the first swap
        ListNode* prev = nullptr;  // To keep track of the previous node

        while(head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            // Adjust the previous node's next pointer
            if(prev) {
                prev->next = second;
            }

            // Swap
            first->next = second->next;
            second->next = first;

            // Move to the next pair
            prev = first;
            head = first->next;
        }

        return newHead;
    }
};
