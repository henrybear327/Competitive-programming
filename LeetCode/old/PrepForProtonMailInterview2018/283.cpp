// :%s/^ \*//g
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
    void moveZeroes(vector<int> &nums)
    {
        /*
        int cur = 0;
        for (int cand = 0; cand < (int)nums.size(); cand++) {
            if (nums[cand] != 0) {
                nums[cur] = nums[cand];
                cur++;
            }
        }
        for (int i = cur; i < (int)nums.size(); i++)
            nums[i] = 0;
        */

        int cur = 0;
        for (int cand = 0; cand < (int)nums.size(); cand++) {
            if (nums[cand] != 0) {
                swap(nums[cand], nums[cur]);
                cur++;
            }
        }
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
