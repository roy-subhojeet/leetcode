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
    ListNode* reverseList(ListNode* head) {

    ListNode *curr = head;
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;



/* not in-place (init sol)
        ListNode* newHead = nullptr;
        while(head != nullptr)
        {
            ListNode *listNode = new ListNode();
            listNode->val = head->val;
            if(newHead != nullptr) listNode->next = newHead;
            newHead = listNode;
            //head = head->next;
            ListNode* temp = head;  // save the current node
            head = head->next;     // move to the next node
            delete temp;           // delete the saved node

        }
        return newHead;
*/
    }
};