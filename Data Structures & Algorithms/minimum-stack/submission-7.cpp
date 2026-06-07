class MinStack {
public:
    stack<int> ogStack;
    stack<int> minStack;

    MinStack() {}
    
    void push(int val) {
        if (!ogStack.empty() && minStack.empty() && val > ogStack.top())
        {
            minStack.push(ogStack.top());
        }
        else if (!minStack.empty() && !ogStack.empty() && val <= minStack.top())
        {
            minStack.push(val);
        }
        ogStack.push(val);
    }
    
    void pop() {
        if (!ogStack.empty() && !minStack.empty())
        {
            if (ogStack.top() == minStack.top())
            {
                minStack.pop();
            }
        }
        ogStack.pop();
    }
    
    int top() {
        return ogStack.top();
    }
    
    int getMin() {
        if (!minStack.empty() && minStack.top() < ogStack.top())
        {
            return minStack.top();
        }
        else 
        {
            return ogStack.top();
        }
    }
};
