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
private:
    int dfs(int l, int r, vector<vector<int>> &dp) // [l, r)
    {
        if (r - l <= 1)
            return dp[l][r] = 1;
        if (dp[l][r] != 0)
            return dp[l][r];

        for (int i = l; i < r; i++) { // for every root
            dp[l][r] += dfs(l, i, dp) * dfs(i + 1, r, dp);
        }

        return dp[l][r];
    }

public:
    int numTrees(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        return dfs(1, n + 1, dp);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
