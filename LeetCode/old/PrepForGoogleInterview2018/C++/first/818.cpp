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

// DP, BFS
class Solution
{
private:
    int getExp(int x)
    {
        for (int i = 0; i < 31; i++)
            if ((1 << i) <= x && x < (1 << (i + 1)))
                return i + 1;
        return -1;
    }

public:
    // DP https://www.youtube.com/watch?v=HzlEkUt2TYs
    int racecar(int target)
    {
        const int N = 10001;
        vector<int> dp(N, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < N; i++) {
            int k = getExp(i);

            if (i == (1 << k) - 1) {
                dp[i] = k;
                continue;
            }

            // over run, return , run
            int v1 = k + 1 + dp[(1 << k) - 1 - i];

            // under run, return, run, return , run
            int v2 = INT_MAX;
            int start = (1 << (k - 1)) - 1;
            int end = (k - 2 < 0 ? 0 : ((1 << (k - 2)) - 1));
            for (int m = 0; start - ((1 << m) - 1) > end; m++) {
                int step = ((1 << m) - 1);
                v2 = min(v2, k - 1 + 1 + m + 1 + dp[i - (start - step)]);
            }

            dp[i] = min(v1, v2);
        }

        return dp[target];
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().racecar(13) << endl;
    return 0;
}
#endif