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

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int cnt[26] = {0};
        for (auto i : s)
            cnt[i - 'a']++;

        bool in[26] = {false};
        stack<char> st;
        for (auto cc : s) {
            int c = cc - 'a';
            cnt[c]--;  // oops
            if (in[c]) // no need to insert again
                continue;

            // observation
            // if the current character is better than the top character in the stack
            // and
            // the top character still has occurrence after the current one:
            // pop it
            while (st.size() > 0 && cc < st.top() && cnt[st.top() - 'a'] > 0) {
                // cnt[st.top() - 'a']++; // don't do this
                in[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(cc);
            in[c] = true;
        }

        // ans
        string ans = "";
        while (st.size() > 0) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif