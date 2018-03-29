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
public:
    // nlogn
    int lengthOfLIS(vector<int> &nums)
    {
        int sz = nums.size() + 1; // case [0], fucked
        if (sz == 0)
            return 0;
        int val[sz];
        fill(val, val + sz, INT_MAX);

        for (const auto &i : nums) {
            auto it = lower_bound(val, val + sz, i) - val;
            val[it] = i;
        }

        for (int i = 0; i < sz; i++)
            if (val[i] == INT_MAX)
                return i;
        return -1;
    }

    // n^2
    // int lengthOfLIS(vector<int> &nums)
    // {
    //     int sz = nums.size();
    //     if (sz == 0)
    //         return 0;

    //     int dp[sz];
    //     fill(dp, dp + sz, 1);
    //     for (int i = 0; i < sz; i++)
    //         for (int j = i + 1; j < sz; j++)
    //             if (nums[j] > nums[i]) {
    //                 dp[j] = max(dp[j], dp[i] + 1); // GG, take max!!
    //             }

    //     int mx = 0;
    //     for (int i = 0; i < sz; i++)
    //         mx = max(mx, dp[i]);

    //     return mx;
    // }
};

int main()
{
    Solution s;
    vector<int> inp;
    inp.push_back(0);
    cout << s.lengthOfLIS(inp) << endl;
    return 0;
}