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
    ListNode* rotateRight(ListNode* head, int k) {

    if(!head || k == 0) return head;

    int cnt = 0;
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while(curr)
    {
        prev = curr;
        curr = curr->next;
        ++cnt;
    }
    cout << cnt;
    if(k > cnt) k = k%cnt;
    if(k == 0 || cnt == k || cnt == 1) return head;
    prev->next = head;
    int tailPos = cnt - k;
    while(tailPos != 0)
    {
        prev = prev->next;
        --tailPos;
        ListNode* temp = prev->next;
        if(tailPos == 0)
        {
            prev->next = nullptr;
            head = temp;
            break;
        }
    }
    return head;


        
    }
};