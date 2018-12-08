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

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto i : s) {
            if (i == '(' || i == '[' || i == '{')
                st.push(i);
            else {
                if (st.size() == 0)
                    return false;
                if (st.top() == '(' && i == ')')
                    st.pop();
                else if (st.top() == '[' &&
                         i == ']') // no else, will have redundant cmp
                    st.pop();
                else if (st.top() == '{' && i == '}')
                    st.pop();
                else
                    return false;
            }
        }

        return st.size() == 0;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
