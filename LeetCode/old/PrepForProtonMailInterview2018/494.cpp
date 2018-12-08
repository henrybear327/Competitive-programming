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
    void dfs(vector<int> &nums, int depth, int acc, int &ans, int &S)
    {
        if (depth == (int)nums.size()) {
            if (acc == S)
                ans++;
            return;
        }

        dfs(nums, depth + 1, acc + nums[depth], ans, S);
        dfs(nums, depth + 1, acc - nums[depth], ans, S);
    }

public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int ans = 0;
        dfs(nums, 0, 0, ans, S);
        int n = nums.size();

        /*
        for (int i = 0; i < (1 << n); i++) {
            int tmp = 0;
            for (int j = 0; j < n;
                 j++) { // this step is causing a lot of redundant calculations
                if ((i >> j) & 1)
                    tmp += nums[j];
                else
                    tmp -= nums[j];
            }

            if (tmp == S)
                ans++;
        }
        */
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
