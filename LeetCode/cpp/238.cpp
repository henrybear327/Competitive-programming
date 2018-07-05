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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int product = 1;
        for (int i = 1; i < n; i++) {
            product *= nums[i - 1];
            dp[i] *= product;
        }

        product = 1;
        for (int i = n - 2; i >= 0; i--) {
            product *= nums[i + 1];
            dp[i] *= product;
        }

        return dp;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
