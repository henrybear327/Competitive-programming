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
        for (int i = 0; i < (int)nums.size(); i++)
            inp[nums[i]] = i;

        for (int i = 0; i < (int)nums.size(); i++) {
            if (inp.count(target - nums[i]) != 0 && i != inp[target - nums[i]])
                return vector<int> {i, inp[target - nums[i]]};
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
