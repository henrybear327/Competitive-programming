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
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = 0x3f3f3f3f;
        int closest = 0x3f3f3f3f;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (abs(target - (nums[i] + nums[j] + nums[k])) < diff) {
                    closest = nums[i] + nums[j] + nums[k];
                    diff = abs(target - closest);
                }

                // we can't skip same values like 3sum since we are not dealing with = 0 case!
                // [-1, 0, 1, 1, 5], target = 2

                if (nums[j] + nums[k] > target - nums[i]) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return closest;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif