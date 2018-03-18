// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int x = []()
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
    int maxProfit(vector<int> &prices)
    {
        int n = (int)prices.size();
        if (n == 0) { // WA
            return 0;
        }

        int mx[n];
        int mn[n];

        mn[0] = prices[0];
        mx[n - 1] = prices[n - 1];
        for (int i = 1; i < n; i++)
            mn[i] = min(mn[i - 1], prices[i]);
        for (int i = n - 2; i >= 0; i--)
            mx[i] = max(mx[i + 1], prices[i]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, mx[i] - mn[i]);
        }

        return ans;
    }
};

int main()
{
    return 0;
}