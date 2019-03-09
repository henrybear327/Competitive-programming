class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> s, mn;
    MinStack() {}

    void push(int x)
    {
        s.push(x);
        if (mn.size() == 0)
            mn.push(x);
        else
            mn.push(min(mn.top(), x));
    }

    void pop()
    {
        s.pop();
        mn.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
