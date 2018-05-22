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
    string decodeString(string s)
    {
        stack<string> st;
        string cur;
        int num = 0;

        // "3[a]2[bc]"
        for (auto i : s) {
            if ('0' <= i && i <= '9') {
                if (num == 0) {
                    st.push(cur);
                    cur = "";
                }

                num = num * 10 + (i - '0');
            } else {
                if (i == '[') {
                    st.push(to_string(num));
                    num = 0;
                } else if (i == ']') {
                    st.push(cur);
                    cur = "";

                    cur = st.top();
                    st.pop();
                    int rep = stoi(st.top());
                    st.pop();

                    string tmp = "";
                    for (int j = 0; j < rep; j++)
                        tmp += cur;
                    cur = st.top() + tmp; // crucial!
                    st.pop();
                    // cout << cur << endl;
                } else {
                    cur += i;
                }
            }
        }

        if (cur != "")
            st.push(cur);

        string ans = "";
        // cout << st.size() << endl;
        while (st.size() > 0) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().decodeString("3[a2[c]]") << endl;
    return 0;
}
#endif