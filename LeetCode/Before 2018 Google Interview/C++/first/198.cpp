// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}
();

// DP, space ship
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // 1 2 3 4 5
        int n = (int)nums.size();
        if (n == 0) // WA
            return 0;
        int dp[n][2];

        dp[0][0] = nums[0]; // pick
        dp[0][1] = 0;       // don't pick
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][1] + nums[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main()
{
    return 0;
}