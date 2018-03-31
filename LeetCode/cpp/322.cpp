// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
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
    int coinChange(vector<int> &coins, int amount)
    {
        int dp[amount + 1];
        fill(dp, dp + amount + 1, 0x3f3f3f3f);
        dp[0] = 0;

        for (auto i : coins) {
            for (int j = 0; i + j <= amount; j++) {
                dp[i + j] = min(dp[i + j], dp[j] + 1); // INT_MAX overflow on + 1
            }
        }

        return dp[amount] == 0x3f3f3f3f ? (amount ? -1 : 0) : dp[amount];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif