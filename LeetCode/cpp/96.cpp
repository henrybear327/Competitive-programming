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

class Solution
{
public:
    int numTrees(int n)
    {
        if (n <= 1)
            return 1;
        vector<int> dp(n + 1, 0);

        dp[0] = dp[1] = 1;

        // from the recursion, we can observe that
        // for a given range [l, r), what matters is not the bound
        // instead, the size of the bound matters! -> 1D

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // size
                // left mid right
                // j    1   n - j - 1
                // printf("i %d j %d: %d %d\n", i, j, dp[j], dp[n - j - 1]);
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[n];
    }
};

// handle special cases first
// [], "", ...
// class Solution
// {
// private:
//     int dfs(int l, int r, vector<vector<int>> &dp) // [l, r)
//     {
//         if (l >= r) // not a possible range
//             return 1;
//         if (l + 1 == r) // only one node
//             return 1;
//         if (dp[l][r] != -1)
//             return dp[l][r];

//         int res = 0;
//         for (int i = l; i < r; i++) {
//             res += dfs(l, i, dp) * dfs(i + 1, r, dp);
//         }

//         return dp[l][r] = res;
//     }

// public:
//     int numTrees(int n)
//     {
//         vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
//         return dfs(1, n + 1, dp);
//     }
// };

#ifdef LOCAL
int main()
{
    cout << Solution().numTrees(1) << endl;
    cout << Solution().numTrees(2) << endl;
    cout << Solution().numTrees(3) << endl;
    cout << Solution().numTrees(4) << endl;
    cout << Solution().numTrees(5) << endl;
    cout << Solution().numTrees(6) << endl;
    return 0;
}
#endif