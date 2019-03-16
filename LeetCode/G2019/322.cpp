class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = amount + 1;
        int dp[n] = {0};
        dp[0] = 0;
        int oo = 0x3f3f3f3f;
        fill(dp + 1, dp + n, oo);
        for (auto i : coins) {
            for (int j = 0; j + i <= amount; j++) {
                if (dp[j] != oo) {
                    dp[i + j] = min(dp[i + j], dp[j] + 1);
                }
            }
        }
        return dp[amount] == oo ? -1 : dp[amount];
    }
};