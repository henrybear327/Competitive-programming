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
private:
    vector<int> tmp;
    void dfs(vector<int> &nums, bool used[], vector<vector<int>> &ans,
             int depth)
    {
        if ((int)nums.size() == depth) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i] == false) {
                tmp.push_back(nums[i]);
                used[i] = true;
                dfs(nums, used, ans, depth + 1);
                used[i] = false;
                tmp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        bool used[nums.size()];
        memset(used, false, sizeof(used));
        dfs(nums, used, ans, 0);

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
