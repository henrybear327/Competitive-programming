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

/*
Good case
[3,1,0,-2]
4
*/
typedef pair<int, int> ii;
class Solution
{
public:
    int threeSumSmaller(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        // enumerate leftmost
        // two pointer on the right interval!
        // What a solution
        int ans = 0;
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            int l = i + 1, r = (int)nums.size() - 1;
            int tmp = 0;
            while (l < r) {
                // nums[l] + nums[(l, r]] will < target - nums[i]!
                // What an observation
                if (nums[l] + nums[r] < target - nums[i]) {
                    tmp += r - l;
                    l++;
                } else {
                    r--;
                }
            }
            ans += tmp;
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
