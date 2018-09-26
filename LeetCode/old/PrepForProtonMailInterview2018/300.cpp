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
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), INT_MAX);

        for (auto i : nums) {
            *lower_bound(dp.begin(), dp.end(), i) = i;
        }

        int ans = nums.size();
        for (int i = 0; i < (int)nums.size(); i++)
            if (dp[i] == INT_MAX) {
                ans = i;
                break;
            }
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
