#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve()
{
    int n, p;
    scanf("%d %d", &n, &p);

    ll inp[n][p];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%lld", &inp[i][j]);
        }
        sort(inp[i], inp[i] + p);
    }

    vector<vector<long long>> dp(2, vector<long long>(n, 1e17));
    dp[1][0] = inp[0][p - 1];
    for (int i = 1; i < n; i++) {
        ll diff = inp[i][p - 1] - inp[i][0];
        dp[0][i] = min(dp[0][i - 1] + abs(inp[i][p - 1] - inp[i - 1][0]),
                       dp[1][i - 1] + abs(inp[i][p - 1] - inp[i - 1][p - 1])) +
                   diff;
        dp[1][i] = min(dp[0][i - 1] + abs(inp[i][0] - inp[i - 1][0]),
                       dp[1][i - 1] + abs(inp[i][0] - inp[i - 1][p - 1])) +
                   diff;
    }

    return min(dp[0][n - 1], dp[1][n - 1]);
}

int main()
{
    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        printf("Case #%d: %lld\n", i, solve());
    }

    return 0;
}

