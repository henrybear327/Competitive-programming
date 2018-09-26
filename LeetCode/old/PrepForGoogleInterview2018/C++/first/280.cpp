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

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();

        // extra space
        // sort(nums.begin(), nums.end());
        // auto it = nums.begin();
        // advance(it, n / 2 + (n % 2 == 1));
        // vector<int> small(nums.begin(), it);
        // vector<int> large(it, nums.end());

        // for (int i = 0; i < (int)small.size(); i++) {
        //     nums[i * 2] = small[i];
        // }
        // for (int i = 0; i < (int)large.size(); i++) {
        //     nums[i * 2 + 1] = large[i];
        // }

        // inplace
        // sort(nums.begin(), nums.end());
        // for (int i = 1; i + 1 < n; i += 2)
        //     swap(nums[i], nums[i + 1]);

        // inplace no sorting, what a solution
        for (int i = 1; i < n; i++) {
            if (i % 2 == 1) { // <=
                if (nums[i - 1] > nums[i])
                    swap(nums[i - 1], nums[i]);
            } else { // >=
                if (nums[i - 1] < nums[i])
                    swap(nums[i - 1], nums[i]);
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