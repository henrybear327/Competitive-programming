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
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[left] == nums[i])
                continue;
            left++;
            nums[left] = nums[i];
        }
        left++;
        return left;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif