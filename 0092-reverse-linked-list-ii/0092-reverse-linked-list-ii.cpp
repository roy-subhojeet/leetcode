class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        int count = 1;
        ListNode * node = head;
        ListNode *lPrev = nullptr;
        ListNode* rPtr = nullptr;

        while(node)
        {
            ++count;
            if(count == left) lPrev = node;
            node = node->next;
            if(count == right) rPtr = node;
        }

        ListNode * current = lPrev ? lPrev->next: head;
        ListNode * next = current->next;
        current->next = rPtr->next;
        ListNode * prev =  current;
        current = next;
        
        for(int i = 0; i < right - left; ++i)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        if(lPrev) lPrev->next = rPtr;
        else head = rPtr;


        return head;

    }
};
