// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (dp[i]) {
                dp[i + 1] += dp[i];
                if (i + 2 <= n)
                    dp[i + 2] += dp[i];
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(3) << endl;
    return 0;
}