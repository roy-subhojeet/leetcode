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

        /* Brute Force
        // Handle empty input
        if (lists.empty()) return nullptr;
        
        // If only one list is there, return it
        if (lists.size() == 1) return lists[0];
        
        ListNode* firstList = lists[0];
        
        for (int i = 1; i < lists.size(); ++i) {
            ListNode* dummyHead = new ListNode(-1);
            ListNode* tail = dummyHead;
            ListNode* secondList = lists[i];
            
            while (firstList && secondList) {
                if (firstList->val <= secondList->val) {
                    tail->next = firstList;
                    firstList = firstList->next;
                } else {
                    tail->next = secondList;
                    secondList = secondList->next;
                }
                tail = tail->next;
            }
            
            if (firstList) tail->next = firstList;
            if (secondList) tail->next = secondList;
            
            firstList = dummyHead->next;
            delete dummyHead;
        }
        
        return firstList;
        */
};
