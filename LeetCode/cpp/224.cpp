#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?
class Solution
{
public:
    int calculate(string s)
    {
        int num = 0, sum = 0;
        int sign = 1;  // 1 plus -1 minus
        stack<int> st; // num, sign, num, sign
        for (auto token : s) {
            if ('0' <= token && token <= '9') { // num
                num = num * 10 + (token - '0');
            } else if (token == ' ') { // space
                continue;
            } else {
                // add the number before ) first
                sum += sign * num;
                num = 0;

                if (token == '(') {
                    // cout << "(" << endl;
                    // cout << sum << " " << sign << endl;

                    st.push(sum);
                    st.push(sign);
                    sum = 0;
                    sign = 1;
                } else if (token == ')') {
                    // pop last result of (
                    assert(st.size() >= 2);
                    sign = st.top();
                    st.pop();
                    // cout << st.top() << " " << sign * sum << endl;
                    sum = st.top() + sign * sum;
                    st.pop();
                } else if (token == '+') {
                    sign = 1;
                } else if (token == '-') {
                    sign = -1;
                } else {
                    cerr << "Error command" << endl;
                    exit(1);
                }
            }
        }

        sum += sign * num;
        return sum;
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().calculate("1 + 1") << endl;
    cout << Solution().calculate(" 2-1 + 2 ") << endl;
    cout << Solution().calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << Solution().calculate("1-(5)") << endl;
    return 0;
}
#endif