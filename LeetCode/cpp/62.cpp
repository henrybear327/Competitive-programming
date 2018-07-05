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
    int uniquePaths(int m, int n)
    {
        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        for (int i = 0; i < m; i++)
            dp[0][i] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[n - 1][m - 1];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
