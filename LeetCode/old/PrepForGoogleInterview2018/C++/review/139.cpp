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
private:
    bool dfs(string &s, unordered_set<string> &dict, int dp[], int start)
    {
        if (start == (int)s.length())
            return true;
        if (dp[start] != -1)
            return dp[start];

        for (int i = 1; start + i <= (int)s.length(); i++) {
            string cand = s.substr(start, i);
            if (dict.count(cand) == 1) {
                int ret = dfs(s, dict, dp, start + i);
                if (ret == true)
                    return (dp[start] = 1);
            }
        }

        return (dp[start] = 0);
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        int dp[s.length() + 1];
        memset(dp, -1, sizeof(dp));
        for (auto i : wordDict)
            dict.insert(i);

        return dfs(s, dict, dp, 0);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
