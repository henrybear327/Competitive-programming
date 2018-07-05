// :%s/^ \* //g
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
private:
    void dfs(int start, vector<int> &nums, vector<int> &res,
             vector<vector<int>> &ans)
    {
        if (start == (int)nums.size()) {
            return;
        }

        for (int i = start; i < (int)nums.size(); i++) {
            res.push_back(nums[i]);
            ans.push_back(res);
            dfs(i + 1, nums, res, ans);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> res;
        ans.push_back(res);
        dfs(0, nums, res, ans);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
