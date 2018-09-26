// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class MinStack
{
private:
    stack<int> st, minSt;

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x)
    {
        st.push(x);
        if (minSt.size() == 0 || x <= minSt.top())
            minSt.push(x);
    }

    void pop()
    {
        if (minSt.size() > 0 && minSt.top() == st.top())
            minSt.pop();
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
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

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
