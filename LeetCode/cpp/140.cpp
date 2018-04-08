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
/*
"catsanddog"
["cat","cats","and","sand","dog"]
"abcd"
["a","abc","b","cd"]
*/
class Solution
{
private:
    vector<string> &dfs(unordered_set<string> &words,
                        unordered_map<int, vector<string>> &dp, string &s,
                        int idx)
    {
        if (idx == (int)s.length())
            return dp[idx];
        if (dp.count(idx) != 0)
            return dp[idx];

        for (int i = 1; idx + i <= (int)s.length(); i++) {
            string tmp = s.substr(idx, i);
            if (words.count(tmp) > 0) {
                auto ret = dfs(words, dp, s, idx + i);
                for (auto j : ret) {
                    dp[idx].push_back(tmp + (j == "" ? "" : " " + j));
                }
            }
        }

        return dp[idx];
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words;
        for (auto i : wordDict)
            words.insert(i);

        unordered_map<int, vector<string>> dp;
        dp[s.length()] = vector<string>({""});
        return dfs(words, dp, s, 0);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif