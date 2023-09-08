class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        int count = 1;
        ListNode * node = head;
        ListNode *lp = nullptr;
        ListNode* rp = nullptr;

        while(node)
        {
            ++count;
            if(count == left) lp = node;
            node = node->next;
            if(count == right) rp = node;
        }

        ListNode * current = lp ? lp->next: head;
        ListNode * next = current->next;
        current->next = rp->next;
        ListNode * prev =  current;
        current = next;
        
        for(int i = 0; i < right - left; ++i)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        if(lp) lp->next = rp;
        else head = rp;


        return head;

    }
};
