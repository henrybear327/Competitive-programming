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
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(vector<int> &nums, bool used[], int depth)
    {
        if (depth == (int)nums.size()) {
            ans.push_back(tmp); // so... push_back is a copy assignment?
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i] == false) {
                used[i] = true;
                tmp.push_back(nums[i]);
                dfs(nums, used, depth + 1);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        ans.clear();
        tmp.clear();

        bool used[nums.size()];
        memset(used, false, sizeof(used));
        dfs(nums, used, 0);

        return ans;
    }
};

int main()
{
    return 0;
}