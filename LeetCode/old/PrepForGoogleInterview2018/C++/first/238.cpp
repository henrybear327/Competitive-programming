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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // one pass from left + one pass from right
        // you got it!
        int sz = nums.size();
        vector<int> ans(sz);
        ans[0] = 1;
        for (int i = 1; i < sz; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int tmp = nums[sz - 1];
        for (int i = sz - 2; i >= 0; i--) {
            ans[i] *= tmp;
            tmp *= nums[i];
        }

        return ans;
        // int left[sz], right[sz];

        // left[0] = nums[0];
        // right[sz - 1] = nums[sz - 1];
        // for (int i = 1; i < sz; i++) {
        //     left[i] = left[i - 1] * nums[i];
        // }

        // for (int i = sz - 2; i >= 0; i--) {
        //     right[i] = right[i + 1] * nums[i];
        // }

        // vector<int> ans(sz, 0);
        // for (int i = 0; i < sz; i++) {
        //     int l = 1, r = 1;
        //     if (i > 0)
        //         l = left[i - 1];
        //     if (i < sz - 1)
        //         r = right[i + 1];
        //     ans[i] = l * r;
        // }

        // return ans;
    }
};

int main()
{
    return 0;
}