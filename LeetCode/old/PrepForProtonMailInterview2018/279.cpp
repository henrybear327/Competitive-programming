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
    int numSquares(int n)
    {
        int dp[n + 1];
        fill(dp, dp + n + 1, INT_MAX);
        dp[0] = 1;

        for (int i = 1; i * i <= n; i++) {
            dp[i * i] = 1; // bug
            for (int j = 0; j + i * i <= n; j++) {
                if (dp[j] != INT_MAX)
                    dp[i * i + j] = min(dp[i * i + j], dp[j] + 1);
            }
        }

        return dp[n];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
