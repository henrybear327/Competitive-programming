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
    int lengthLongestPath(string input)
    {
        if (input.length() == 0)
            return 0;

        stringstream ss;
        ss.str(input);

        int ans = 0;
        string token;
        stack<int> st; // push the acc length of each level
        while (getline(ss, token, '\n')) {
            // get \t to know depth
            int tab = 0;
            for (int i = (int)token.size() - 1; i >= 0; i--) {
                if (token[i] == '\t') {
                    tab = i + 1;
                    break;
                }
            }

            while ((int)st.size() > tab) {
                st.pop();
            }

            int len = token.length();
            len -= tab;
            if (tab > 0) {
                len += 1; // for /

                len += st.top();
            }

            if (find(token.begin(), token.end(), '.') != token.end())
                ans = max(ans, len);

            // cout << token << " " << len;
            st.push(len);
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif