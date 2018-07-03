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
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        for (auto i : nums) {
            if (nums[abs(i) - 1] > 0)
                nums[abs(i) - 1] = -nums[abs(i) - 1];
        }

        vector<int> ans;
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] > 0)
                ans.push_back(i + 1);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
