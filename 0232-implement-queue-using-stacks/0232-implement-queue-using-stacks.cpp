class MyQueue {
public:
    MyQueue() {
        
    }

    stack<int> st1;
    stack<int> st2;
    int top;
    
    void push(int x) {
        if(st1.empty()) top = x;
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty())
        {       
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int j = st2.top();
        st2.pop();
        return j;
    }
    
    int peek() {
        if(st2.empty()) return top;
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */