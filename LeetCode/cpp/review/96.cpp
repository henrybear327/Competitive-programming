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
// range of input?
class Solution
{
public:
    int numTrees(int n)
    {
        int dp[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                // cout << n << " " << i << " " << j << endl;
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[n];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif