class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
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
    }
};
