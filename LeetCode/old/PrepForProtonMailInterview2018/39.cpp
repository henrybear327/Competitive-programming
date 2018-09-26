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
    int sum;
    vector<int> cur;
    vector<vector<int>> ans;
    void dfs(int start, vector<int> &candidates, int &target)
    {
        if (sum > target)
            return;

        for (int i = start; i < (int)candidates.size(); i++) {
            cur.push_back(candidates[i]);
            sum += candidates[i];
            if (target == sum) {
                ans.push_back(cur);
            }
            dfs(i, candidates, target);
            sum -= candidates[i];
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        sum = 0;
        dfs(0, candidates, target);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
