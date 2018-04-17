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
static int initialSetup = []()
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
private:
    vector<int> tmp;
    void dfs(int start, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (start == (int)nums.size())
            return;

        for (int i = start; i < (int)nums.size(); i++) {
            tmp.push_back(nums[i]);
            ans.push_back(tmp);
            dfs(i + 1, nums, ans);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        ans.push_back(vector<int>()); // watch out
        dfs(0, nums, ans);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
