#include <bits/stdc++.h>

using namespace std;

// 23:35 23:54

void solve()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    int dp[n][2];
    for (int i = 0; i < min(3, n); i++) {
        dp[i][0] = inp[i];
        dp[i][1] = 0;

        if (i > 0)
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }

    for (int i = min(3, n); i < n; i++) {
        dp[i][0] = max(dp[i - 3][0], dp[i - 3][1]) + inp[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, max(dp[i][0], dp[i][1]));
    printf("%d\n", mx);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--)
        solve();

    return 0;
}
