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

// class Solution
// {
// private:
//     int count = 0;

// public:
//     int findTargetSumWays(vector<int> &nums, int S)
//     {
//         calculate(nums, 0, 0, S);
//         return count;
//     }

//     void calculate(vector<int> &nums, int i, int sum, int S)
//     {
//         if (i == (int)nums.size()) {
//             if (sum == S)
//                 count++;
//         } else {
//             calculate(nums, i + 1, sum + nums[i], S);
//             calculate(nums, i + 1, sum - nums[i], S);
//         }
//     }
// };

class Solution
{
private:
    int cnt = 0;

public:
    void cal(vector<int> &nums, int S, int idx, int sum)
    {
        if (idx == (int)nums.size()) {
            if (sum == S)
                cnt++;
            return;
        }

        cal(nums, S, idx + 1, sum + nums[idx]);
        cal(nums, S, idx + 1, sum - nums[idx]);
    }

    int findTargetSumWays(vector<int> &nums, int S)
    {
        cnt = 0;
        cal(nums, S, 0, 0);
        return cnt;
    }
    // int findTargetSumWays(vector<int> &nums, int S)
    // {
    //     int sz = nums.size();
    //     int ans = 0;

    //     int upperBound = (1 << sz);
    //     for (int i = 0; i < upperBound; i++) {
    //         int sum = 0;
    //         for (int j = 0; j < sz; j++) { // this has a factor of n
    //         implication
    //             if ((i >> j) & 1) {
    //                 sum += nums[j];
    //             } else {
    //                 sum -= nums[j];
    //             }
    //         }

    //         if (sum == S) {
    //             ans++;
    //         }
    //     }

    //     return ans;
    // }
};

int main()
{
    return 0;
}