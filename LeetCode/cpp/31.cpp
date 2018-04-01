#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    /* 
    observation: next permutation is always >= the current permutation
    
    Pass one: look from right to left (attempt to find the next smallest >= number)
    try to find the right most pos that can be swapped using a number on its right, to make it bigger (minimax)

    Pass two: look from the swapped pos + 1 to the right (attempt to minimize the permutation)
    
    e.g.
    1 2 4 3
    pass one will have 1 3 4 2 (minimax for pos 2 is 3)
    pass two will have 1 3 2 4
    */
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        bool hasSwap = false;
        int i;
        for (i = n - 1; i >= 0; i--) {
            int mn_mx = INT_MAX, idx = -1;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j] && nums[j] < mn_mx) {
                    mn_mx = nums[j];
                    idx = j;
                }
            }
            if (idx == -1)
                continue;

            swap(nums[i], nums[idx]);
            hasSwap = true;
            break;
        }
        if (hasSwap == false) {
            sort(nums.begin(), nums.end());
            return;
        }

        for (i = i + 1; i < n; i++) {
            int mn = nums[i], idx = -1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < mn) {
                    mn = nums[j];
                    idx = j;
                }
            }

            if (idx == -1)
                continue;
            swap(nums[i], nums[idx]);
        }
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
    vector<int> inp({1, 2, 3});
    for (auto i : inp)
        printf("%d ", i);
    puts("");
    for (int r = 0; r < 6; r++) {
        s.nextPermutation(inp);
        for (auto i : inp)
            printf("%d ", i);
        puts("");
    }
    return 0;
}
#endif