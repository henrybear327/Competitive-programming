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
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        if (grid[0].size() == 0)
            return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < (int)grid.size(); i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < (int)grid[0].size(); j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];

        for (int i = 1; i < (int)grid.size(); i++)
            for (int j = 1; j < (int)grid[0].size(); j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
