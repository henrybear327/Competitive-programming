#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        long long dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        dp[1][0] = dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        printf("%d things taken %d at a time is %lld exactly.\n", n, m, dp[n][m]);
    }

    return 0;
}
