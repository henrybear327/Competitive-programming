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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<int, int> seen;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (seen.find(target - nums[i]) != seen.end()) {
                ans.push_back(seen[target - nums[i]]);
                ans.push_back(i);
                break;
            }

            seen[nums[i]] = i;
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
