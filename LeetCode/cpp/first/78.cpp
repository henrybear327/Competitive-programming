// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

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
    void dfs(int level, vector<vector<int>> &ans, vector<int> &nums,
             vector<int> &tmp, bool used[])
    {
        ans.push_back(tmp);
        if (level == (int)nums.size())
            return;

        for (int i = level; i < (int)nums.size(); i++) { // 123 no 132, etc.
            // for (int i = 0; i < (int)nums.size(); i++) { // 123 and 132, etc.
            if (used[i] == false) {
                used[i] = true;
                tmp.push_back(nums[i]);
                dfs(i + 1, ans, nums, tmp, used);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> tmp;
        vector<vector<int>> ans;
        bool used[nums.size()];
        memset(used, false, sizeof(used));
        dfs(0, ans, nums, tmp, used);
        return ans;
    }
};

int main()
{
    return 0;
}