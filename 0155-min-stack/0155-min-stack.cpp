#include <cstddef>
#include <limits.h>

//template <typename T>
class MinStack{
    private:
        struct Node{
            int val;
            Node *next;
            int minVal = INT_MAX;
        };
    size_t stackSize = 0;
    Node *topNode = nullptr; 

    public:
    MinStack(){}

    ~ MinStack(){}
    void push(const int &val)
    {
        cout << "h" << val << endl;
        Node *newNode = new Node;
        if(topNode && topNode->minVal < val)  newNode->minVal = topNode->minVal;
        else 
        {
            cout << val << endl;
            newNode->minVal = val;
        }
        newNode->val = val;
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop()
    {
        if(topNode != nullptr)
        {
            Node *tempNode = topNode;
            topNode = tempNode->next;
            delete tempNode;
        }
    }

    int top()
    {
        if(topNode != nullptr)
        {
            return topNode->val;
        }
        return NULL;
    }

    int getMin()
    {
        if(topNode) return topNode->minVal;       
        return NULL;
    }

};