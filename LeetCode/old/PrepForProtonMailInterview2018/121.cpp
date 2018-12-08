// :%s/^ \*//g
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
public:
    int maxProfit(vector<int> &prices)
    {
        int mn = 0x3f3f3f3f;
        int ans = 0;
        for (auto i : prices) {
            ans = max(ans, i - mn);
            mn = min(mn, i);
        }
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
