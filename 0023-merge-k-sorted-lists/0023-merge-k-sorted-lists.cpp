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
    struct Compare
    {
        bool operator() (ListNode *a, ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(auto & l : lists)
        {
            if(l) pq.push(l); // all heads in pq
        }
        if(pq.empty()) return nullptr;
        ListNode* head = pq.top();
        ListNode* tail = head;
        pq.pop();
        if(head && head->next) pq.push(head->next);
        while(pq.size() != 0)
        {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if(tail->next) pq.push(tail->next);
        }
        return head;


        
    }
};