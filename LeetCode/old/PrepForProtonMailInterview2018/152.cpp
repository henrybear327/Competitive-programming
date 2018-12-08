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
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int dp[2][nums.size()];
        dp[0][0] = dp[1][0] = nums[0];
        int mx = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            dp[0][i] =
                max(nums[i], max(dp[0][i - 1] * nums[i], dp[1][i - 1] * nums[i]));
            dp[1][i] =
                min(nums[i], min(dp[0][i - 1] * nums[i], dp[1][i - 1] * nums[i]));

            mx = max(mx, dp[0][i]);
        }

        return mx;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
