class MinStack
{
	private:
        struct ListNode
        {
            ListNode* next;
            int val;
            int minVal = INT_MAX;
            ListNode(int val) : val(val), next(nullptr){}
        };
        ListNode* tail = new ListNode(INT_MAX);
        ListNode* curr = tail;

	public:
	MinStack(){}

	~MinStack()
    {
        while(curr != nullptr)
        {
            ListNode* next = curr->next;
            delete curr;
            curr = next;
        }
    }
	void push(int val)
	{
		ListNode* newNode = new ListNode(val);
        if(tail->minVal > val) newNode->minVal = val;
        else  newNode->minVal = tail->minVal;
		newNode->next = tail;
		tail = newNode;
    }
	void pop()
    {
        if(tail->next == nullptr) return;
        ListNode *temp = tail;
        tail = tail->next;
        delete temp;
    }
    int top()
    {
        return tail->val;
    }
    int getMin()
    {
        return tail->next == nullptr ? -1: tail->minVal;
    }
};
