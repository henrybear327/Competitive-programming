#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll dp[55][55][55];
ll cal(int n, int k, int m)
{
    if (n == 0 || k == 0 || m == 0)
        return 0;
    if (k > n || m > n)
        return 0;
    if (k == 1) {
        if (n == m)
            return 1;
        return 0;
    }

    if (dp[n][k][m] != -1)
        return dp[n][k][m];

    ll ret = 0;
    for (int i = 1; i <= m; i++) {
        // add one group of bar with length i to the end of the set (n - i, k - 1, ...)
        // so just make sure that i is not longer than m
        // also, change the m when recursing
        ret += cal(n - i, k - 1, min(m, n - i));
    }
    return dp[n][k][m] = ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[1][1][1] = 1;
    int n, k, m;
    while (scanf("%d %d %d", &n, &k, &m) == 3) {
        printf("%lld\n", cal(n, k, m));
    }

    return 0;
}
