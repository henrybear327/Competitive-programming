// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int dp[n][m];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1; i < n; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

        return dp[n - 1][m - 1];
    }
};

int main()
{
    return 0;
}