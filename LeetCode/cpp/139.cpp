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
private:
    unordered_map<string, bool> dp; // this is crucial!
    bool dfs(string s, unordered_set<string> &dict)
    {
        // cout << s << endl;
        if (0 == (int)s.length()) {
            return true;
        }

        if (dp.find(s) != dp.end())
            return dp[s];

        string cand = "";
        for (int i = 0; i < (int)s.length(); i++) {
            cand += s[i];
            if (dict.find(cand) != dict.end()) {
                bool ret = dfs(s.substr(i + 1, s.length()), dict);
                if (ret) {
                    dp[s] = true;
                    return true;
                }
            }
        }

        dp[s] = false;
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        for (auto i : wordDict)
            dict.insert(i);

        return dfs(s, dict);
    }
};

#ifdef LOCAL
int main()
{
    vector<string> dict({"leet", "code"});
    cout << Solution().wordBreak("leetcode", dict) << endl;
    return 0;
}
#endif