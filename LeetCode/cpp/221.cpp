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
public:
    // to get a square of size n
    // you must have [i - 1][j - 1], [i - 1][j], and [i][j - 1] all having at
    // least size n - 1 (draw it!)
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    ans = 1;
                }

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++) {
                if (dp[i][j] == 0) // WA: oops
                    continue;
                int mn = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);

                dp[i][j] = mn + 1;
                ans = max(ans, dp[i][j]);
            }

        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < m; j++)
        //         printf("%d%c", dp[i][j], j == m - 1 ? '\n' : ' ');
        return ans * ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif