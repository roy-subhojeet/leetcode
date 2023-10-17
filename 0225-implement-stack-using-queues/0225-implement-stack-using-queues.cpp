class MyStack {
public:
    queue<int> q1;
    MyStack() {

    }
    
    void push(int x) 
    {
        q1.push(x);
        for(int i = 1; i < q1.size(); ++i)
        {
            int j = q1.front();
            q1.push(j);
            q1.pop();
        }
    }
    
    int pop() {
        int j = q1.front();
        q1.pop();
        return j;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */