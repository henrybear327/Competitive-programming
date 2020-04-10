class MinStack {
private:
    stack<int> data, mn;
public:
    /** initialize your data structure here. */
    MinStack() {
        this->data = stack<int>();
        this->mn = stack<int>();
    }
    
    void push(int x) {
        data.push(x);
        if(mn.size() > 0) {
            mn.push(min(mn.top(), x));
        } else {
            mn.push(x);
        }
    }
    
    void pop() {
        data.pop();
        mn.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
