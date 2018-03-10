// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

// class MinStack
// {
// private:
//     vector<int> s;
//     vector<int> mn;

// public:
//     /** initialize your data structure here. */
//     MinStack()
//     {
//         s.clear();
//         mn.clear(); // idea: min so far
//     }

//     void push(int x)
//     {
//         s.push_back(x);

//         if (mn.size() == 0 || x <= mn.back()) {
//             mn.push_back(x);
//         }
//     }

//     void pop() // crash on invalid operation
//     {
//         if (s.back() == mn.back()) {
//             mn.pop_back();
//         }

//         s.pop_back();
//     }

//     int top()
//     {
//         return s.back();
//     }

//     int getMin()
//     {
//         return mn.back();
//     }
// };

class MinStack
{
private:
    stack<int> s;
    stack<int> mn;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        s = stack<int>();
        mn = stack<int>();
    }

    void push(int x)
    {
        s.push(x);

        if (mn.size() == 0 || x <= mn.top()) {
            mn.push(x);
        }
    }

    void pop() // crash on invalid operation
    {
        if (s.top() == mn.top()) {
            mn.pop();
        }

        s.pop();
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

int main()
{
    return 0;
}