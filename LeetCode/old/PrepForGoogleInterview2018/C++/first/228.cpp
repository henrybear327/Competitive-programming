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
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        if ((int)nums.size() == 0)
            return ans;
        else if ((int)nums.size() == 1) {
            ans.push_back(to_string(nums[0]));
            return ans;
        }

        int l = nums[0], r = nums.back();
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                continue;
            } else {
                r = nums[i - 1];

                if (l == r)
                    ans.push_back(to_string(l));
                else
                    ans.push_back(to_string(l) + "->" + to_string(r));

                l = nums[i];
                r = nums.back();
            }
        }

        if (l == r)
            ans.push_back(to_string(l));
        else
            ans.push_back(to_string(l) + "->" + to_string(r));

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif