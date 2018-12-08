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
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 0)); // dp[2][n]

        if (n == 0)
            return 0;
        dp[0][0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[1][i - 1] + nums[i];
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
        }

        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
