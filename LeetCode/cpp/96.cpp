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
class Solution
{
private:
    int dfs(int l, int r, vector<vector<int>> &dp) // [l, r)
    {
        if (l >= r) // not a possible range
            return 1;
        if (l + 1 == r) // only one node
            return 1;
        if (dp[l][r] != -1)
            return dp[l][r];

        int res = 0;
        for (int i = l; i < r; i++) {
            res += dfs(l, i, dp) * dfs(i + 1, r, dp);
        }

        return dp[l][r] = res;
    }

public:
    int numTrees(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return dfs(1, n + 1, dp);
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().numTrees(1) << endl;
    cout << Solution().numTrees(2) << endl;
    cout << Solution().numTrees(3) << endl;
    return 0;
}
#endif