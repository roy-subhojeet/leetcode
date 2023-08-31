class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Reverse the linked list and get 'ln' using new nodes

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        //reverse the linked list
        ListNode* nxt = nullptr;
        ListNode* current = slow->next;
        ListNode* prev = nullptr;


        while(current)
        {
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }

        slow->next = nullptr; // head also is half the size now

        ListNode * list1 = head;

        while(prev)
        {
            ListNode *temp = list1->next;    // temp:   2 3              | 3    # temporarily store the next elements of first list
            list1->next = prev;              // list1 or head: 1 5 4     | 4    # connect 1st node of list1 with list2
            list1 = temp;                    //                2 3       | 3    # update list 1 with it's next elements to be processed

            temp = prev->next;               // 4                        | []   # temporarily store the next elements of second list
            prev->next = list1;              // 5 2 3                    | 3    # connect 1st node of list2 with list1
            prev = temp;                     // 4                        | []   # update list 2 with it's next elements to be processed
                                             // 1 - 5 - 2 connected
                                             // list1: 2 3 ; list2: 4
                                             // head: 1 5 2 3
                                             //nodes 2,3 from list 1 pending
                                             //nodes 4 pending to be connected
                                                /*
                                                In simple words, the loop is taking one node at a time from each of the two lists 
                                                (first and second), and placing the second node immediately after the first node.

                                                For example, if initially:

                                                first list is a -> b -> c
                                                second list is x -> y -> z
                                                After one iteration of the loop, the combined list will be:

                                                a -> x -> b -> c
                                                After the second iteration:

                                                a -> x -> b -> y -> c
                                                And so on.
                                                */

        }
    }
};
