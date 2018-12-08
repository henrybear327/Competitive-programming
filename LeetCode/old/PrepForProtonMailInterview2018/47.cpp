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
    vector<bool> used;
    vector<int> cur;
    void dfs(vector<vector<int>> &ans, int depth, vector<int> &nums)
    {
        if (depth == (int)nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i] == false) {
                if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) // curcial!
                    continue;
                used[i] = true;
                cur.push_back(nums[i]);
                dfs(ans, depth + 1, nums);
                cur.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        cur = vector<int>();
        used = vector<bool>(nums.size(), false);
        dfs(ans, 0, nums);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
