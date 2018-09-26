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
    int coinChange(vector<int> &coins, int amount)
    {
        vector<long long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (long long i = 0; i <= amount; i++) {
            for (auto j : coins) {
                if (i + j <= amount)
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
