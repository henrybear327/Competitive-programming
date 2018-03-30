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
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int pre[n + 1];
        pre[0] = 0;
        for (int i = 0; i < n; i++)
            pre[i + 1] = nums[i] + pre[i];

        unordered_map<int, int> cnt;
        cnt[0]++;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int diff = pre[i] - k; // pre[i] - x = k -> x = pre[i] - k;
            ans += cnt[diff];
            cnt[pre[i]]++;
        }

        return ans;
    }
};

int main()
{
    return 0;
}