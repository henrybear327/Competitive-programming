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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> inp;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (inp.find(target - nums[i]) != inp.end())
                return vector<int> {inp[target - nums[i]], i};
            inp[nums[i]] = i;
        }

        return vector<int>();
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif