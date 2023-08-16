class Stack {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int val) {
        if (topIndex < capacity - 1) {
            arr[++topIndex] = val;
        }
    }

    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        }
    }

    int top() {
        if (topIndex >= 0) {
            return arr[topIndex];
        }
        return -1;  // Error value, should handle this appropriately in real-world scenarios
    }

    bool empty() {
        return topIndex == -1;
    }
};

class MinStack {
private:
    Stack mainStack;
    Stack minStack;

public:
    MinStack(int size = 30000) : mainStack(size), minStack(size) {}  // Default size set to 30000 as per problem constraints

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
