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
    void dfs(vector<int> &candidates, int target, int i, int sum,
             vector<vector<int>> &ans, vector<int> &tmp)
    {
        if (sum == target) {
            ans.push_back(tmp);
            return;
        } else if (sum > target) { // candidates are all positive integers, so ...
            return;
        }

        if (i >= (int)candidates.size())
            return;

        tmp.push_back(candidates[i]);
        dfs(candidates, target, i, sum + candidates[i], ans, tmp); // pick
        tmp.pop_back();

        dfs(candidates, target, i + 1, sum, ans, tmp); // don't pick
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;

        dfs(candidates, target, 0, 0, ans, tmp);
        return ans;
    }
};

int main()
{
    return 0;
}