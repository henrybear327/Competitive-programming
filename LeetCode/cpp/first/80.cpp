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
    int removeDuplicates(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        if (nums.size() == 0)
            return 0;

        int left = 0;
        int cnt = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[left] == nums[i]) {
                cnt++;
                continue;
            }

            if (cnt >= 2) {
                nums[left + 1] = nums[left];
                left += 2;
            } else {
                left++;
            }

            nums[left] = nums[i];
            cnt = 1;
        }

        if (cnt >= 2) {
            nums[left + 1] = nums[left];
            left += 2;
        } else
            left += 1;
        return left;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif