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
// range of input?
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int mx[n], mn[n];

        mx[0] = nums[0];
        mn[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            mx[i] = max(nums[i], max(mx[i - 1] * nums[i], mn[i - 1] * nums[i]));
            mn[i] = min(nums[i], min(mx[i - 1] * nums[i], mn[i - 1] * nums[i]));

            ans = max(ans, mx[i]);
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