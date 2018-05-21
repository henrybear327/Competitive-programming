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
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0;
        /*
        https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
        State disgram,
        where S0, S1, and S2 all have self loop of rest
        S0 ---buy---> S1 ---sell---> S2
        ^                             |
        |                             |
        |------------rest-------------<
        */
        vector<vector<int>> dp(3, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0]; // because dp[2] will be using it! 
        dp[2][0] = 0;
        for (int i = 1; i <= n; i++) {
            int price = prices[i - 1];
            dp[0][i] = max(dp[0][i - 1], dp[2][i - 1]);
            // -price here so when you sell you get the diff value! Cool!
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + -price);
            dp[2][i] = max(dp[2][i - 1], dp[1][i - 1] + price);
        }

        return dp[2][n];
    }
};

#ifdef LOCAL
int main()
{
    vector<int> inp({1, 2, 3, 0, 2});
    cout << Solution().maxProfit(inp) << endl;
    return 0;
}
#endif