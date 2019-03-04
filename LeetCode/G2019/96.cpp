class Solution
{
public:
    int numTrees(int n)
    {
        int dp[max(3, n + 1)] = {0}; // mind the case where n <= 2
        dp[0] = 1;                   // important base case
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};
