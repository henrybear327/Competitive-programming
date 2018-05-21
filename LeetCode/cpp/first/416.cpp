// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
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
    // https://leetcode.com/problems/partition-equal-subset-sum/discuss/90588/Concise-C++-Solution-summary-with-DFS-DP-BIT
    // genius solution (bit trick)
    // bool canPartition(vector<int> &nums)
    // {
    //     bitset<5001> bits(1);
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     for (auto n : nums)
    //         bits |= bits << n;
    //     return !(sum & 1) && bits[sum >> 1];
    // }

    bool canPartition(vector<int> &nums)
    {
        bool dp[22222];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        int sum = 0;
        for (auto i : nums)
            sum += i;

        for (auto i : nums)
            for (int j = sum / 2; j >= 0; j--) {
                if (dp[j] == true && i + j < 22222)
                    dp[i + j] = true;
            }

        return sum % 2 == 1 ? false : dp[sum / 2];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif