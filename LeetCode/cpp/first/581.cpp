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
    int findUnsortedSubarray(vector<int> &nums)
    {
        // size 0 case - ok
        vector<int> ans(nums.begin(), nums.end());

        sort(ans.begin(), ans.end());

        // int left = nums.size() - 1, right = nums.size() - 1;
        // for (int i = 0; i < (int)nums.size(); i++) {
        //     if (nums[i] != ans[i]) {
        //         left = i;
        //         break;
        //     }
        // }

        // for (int i = (int)nums.size() - 1; i >= 0; i--) {
        //     if (nums[i] != ans[i]) {
        //         right = i;
        //         break;
        //     }
        // }

        int left = nums.size(), right = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (ans[i] != nums[i]) {
                left = min(left, i);
                right = max(right, i);
            }
        }

        // return left == right ? 0 : right - left + 1;
        return right >= left ? right - left + 1 : 0;
    }
};

int main()
{
    return 0;
}