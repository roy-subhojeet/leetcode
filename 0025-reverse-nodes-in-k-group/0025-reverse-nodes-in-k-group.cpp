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

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* curr = head;
        ListNode* newHead = nullptr;
        ListNode* tailPrev = nullptr;
        while(curr)
        {
            int len = 0;
            int K = k;
            while(K > 0 && curr)
            {
                curr = curr->next;
                --K;
                ++len;
            }
            if(k == len)
            {
                ListNode* revHead = reverseLinkedList(head, k);
                if(newHead == nullptr) newHead = revHead;
                if(tailPrev != nullptr)
                {
                    tailPrev->next = revHead;
                }
                tailPrev = head;
                head = curr;
            }
        }
        if(tailPrev) tailPrev->next = head;
        return newHead;
    }

    ListNode* reverseLinkedList(ListNode* head, int k)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(k > 0)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            --k;
        }
        return prev;
    }












/* Recursive Solution

    ListNode* reverseList(ListNode* head, int k)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(k > 0)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            --k;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        int count = 0;
        while(count < k && ptr != nullptr)
        {
            ptr = ptr->next;
            ++count;
        }

        if(count == k)
        {
            ListNode* l1 = reverseList(head, k);
            head->next = reverseKGroup(ptr, k);
            return l1;
        }

        return head;
        
    }
*/
};