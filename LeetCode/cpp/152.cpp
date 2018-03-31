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
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        // keep the mx/mn so far
        // when you encounter a positive number -> mx increases
        // when you encounter a negative number -> mn decreases
        // mx can come from neg mn * neg number!

        // cases to consider
        // 1. current number
        // 2. mx/mn (previous best) * current number
        int mx = nums[0], mn = nums[0], ans = max(mx, mn);
        for (int i = 1; i < (int)nums.size(); i++) {
            int num = nums[i];

            // int orig_mx = mx;
            // int orig_mn = mn;
            // mx = max(num, max(orig_mx * num, orig_mn * num));
            // mn = min(num, min(orig_mn * num, orig_mx * num));

            if (num < 0) { // crucial!
                swap(mx, mn);
            }
            mx = max(num, mx * num);
            mn = min(num, mn * num);

            ans = max(ans, max(mx, mn));
            printf("%d : %d %d %d\n", i, ans, mx, mn);
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    // vector<int> inp({2, 3, -2, 4});
    // vector<int> inp({-4, -3, -2});
    vector<int> inp({-2, 3, -4});
    Solution s;
    printf("%d\n", s.maxProduct(inp));
    return 0;
}
#endif