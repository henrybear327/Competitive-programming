#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // since we only pick up the inc
        // we get..... so simplied version....
        if (prices.size() <= 0)
            return 0;
        int ans = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            if (prices[i - 1] < prices[i])
                ans += prices[i] - prices[i - 1];
        }
        return ans;

        // int ans = 0, prev = prices[0], idx = 0;
        // for (int i = 1; i < (int)prices.size(); i++) {
        //     if (prices[i - 1] > prices[i]) {
        //         if (idx != i - 1) {
        //             ans += prices[i - 1] - prev;
        //         }
        //         prev = prices[i];
        //         idx = i;
        //     }
        // }

        // if (idx != (int)prices.size() - 1) {
        //     ans += prices[(int)prices.size() - 1] - prev;
        // }
        // return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif