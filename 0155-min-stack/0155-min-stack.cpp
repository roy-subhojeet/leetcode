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

    ~ MinStack(){
        while(topNode)
        {
            this->pop();
        }
    }
    void push(const int &val)
    {
        Node *newNode = new Node;
        if(topNode && topNode->minVal < val)  newNode->minVal = topNode->minVal;
        else 
        {
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