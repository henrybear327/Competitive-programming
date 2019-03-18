class Solution
{
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, vector<bool> &used, vector<int> &cur)
    {
        if (nums.size() == cur.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i] == false) {
                cur.push_back(nums[i]);
                used[i] = true;
                dfs(nums, used, cur);
                used[i] = false;
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        vector<int> cur;
        dfs(nums, used, cur);
        return ans;
    }
};
