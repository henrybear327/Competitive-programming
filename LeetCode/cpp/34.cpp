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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        if (distance(lb, ub) == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
        } else {
            ans.push_back(lb - nums.begin());
            ub--;
            ans.push_back(ub - nums.begin());
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