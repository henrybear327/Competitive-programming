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
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> orig = nums;
        sort(nums.begin(), nums.end());

        int left = INT_MAX;
        int right = INT_MIN;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != orig[i]) {
                left = min(i, left);
                right = max(i, right);
            }
        }

        if (left == INT_MAX || right == INT_MIN)
            return 0;
        else
            return right - left + 1;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
