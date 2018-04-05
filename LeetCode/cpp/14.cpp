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

// prefix tree -> trie
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";

        int ans = 0; // length of LCP
        while (ans < (int)strs[0].size()) {
            char c = strs[0][ans];
            for (int i = 0; i < (int)strs.size(); i++) {
                if (ans >= (int)strs[i].size() || c != strs[i][ans]) {
                    return strs[0].substr(0, ans);
                }
            }

            ans++;
        }
        return strs[0].substr(0, ans);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif