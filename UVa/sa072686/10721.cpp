#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k, m;
    while (scanf("%d %d %d", &n, &k, &m) == 3) {
        ll dp[55][55];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        // dp[i][j] = ans for i groups, j bars, and at most m bars per groups
        // start with 1 group, 1...n bars
        //            2 groups, for every bar count j, try to extent it with 1 group (j - (1 ~ m))
        for (int i = 1; i <= k; i++) {     // groups
            for (int j = 1; j <= n; j++) {   // bars
                for (int x = 1; x <= m; x++) { // at most x bars
                    if (j - x >= 0)
                        dp[i][j] += dp[i - 1][j - x];
                }
            }
        }
        printf("%lld\n", dp[k][n]); // (k, n, m), m is fixed for this dp table
    }

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// typedef pair<int, int> ii;

// ll dp[55][55][55];
// ll cal(int n, int k, int m)
// {
//     if (n == 0 || k == 0 || m == 0)
//         return 0;
//     if (k > n || m > n)
//         return 0;
//     if (k == 1) {
//         if (n == m)
//             return 1;
//         return 0;
//     }

//     if (dp[n][k][m] != -1)
//         return dp[n][k][m];

//     ll ret = 0;
//     for (int i = 1; i <= m; i++) {
//         // add one group of bar with length i to the end of the set (n - i, k - 1,
//         // ...) so just make sure that i is not longer than m also, change the m
//         // when recursing
//         ret += cal(n - i, k - 1, min(m, n - i));
//     }
//     return dp[n][k][m] = ret;
// }

// int main()
// {
//     int n, k, m;
//     while (scanf("%d %d %d", &n, &k, &m) == 3) {
//         recursive
//         memset(dp, -1, sizeof(dp));
//         dp[1][1][1] = 1;
//         printf("%lld\n", cal(n, k, m));
//     }

//     return 0;
// }

