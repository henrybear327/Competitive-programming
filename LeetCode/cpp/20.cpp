// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (st.size() <= 0)
                    return false;

                if (c == ')' && st.top() == '(') {
                    st.pop();
                } else if (c == ']' && st.top() == '[') {
                    st.pop();
                } else if (c == '}' && st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.size() > 0 ? false : true; // WA: st.top() > 0 case
    }
};

int main()
{
    string s = "()";
    Solution ss;
    cout << ss.isValid(s) << endl;
    return 0;
}