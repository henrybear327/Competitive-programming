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

typedef pair<int, int> ii;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int x = j + 1, y = n - 1;

                while (x < y) {
                    int diff = target - nums[i] - nums[j];
                    if (diff == nums[x] + nums[y]) {
                        ans.push_back(vector<int> {nums[i], nums[j], nums[x], nums[y]});

                        while (x + 1 < y && nums[x] == nums[x + 1])
                            x++;
                        while (x < y - 1 && nums[y - 1] == nums[y])
                            y--;
                    }

                    if (diff > nums[x] + nums[y]) {
                        x++; // can't do duplicate elem speed up!
                    } else {
                        y--;
                    }
                }
            }
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