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
    void dfs(vector<int> &nums, int depth, vector<int> &seq,
             vector<vector<int>> &ans, vector<bool> &used)
    {
        if (depth == (int)nums.size()) {
            ans.push_back(seq);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i] == false) {
                used[i] = true;
                seq.push_back(nums[i]);
                dfs(nums, depth + 1, seq, ans, used);
                seq.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> seq;
        vector<bool> used(nums.size(), false);
        dfs(nums, 0, seq, ans, used);

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
