#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);

    vector<vector<int>> inp(n, vector<int>(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++) {
            scanf("%d", &inp[i][j]);
            if (j > 0)
                inp[i][j] = inp[i][j - 1] + inp[i][j];
        }

    int dp[n][p + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < k && i + 1 <= p; i++) // on my god, the init is killing me
        dp[0][i + 1] = inp[0][i];

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j <= p; j++) {
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);

            for (int x = 0; x < k && j + x + 1 <= p; x++) {
                dp[i + 1][j + x + 1] =
                    max(dp[i + 1][j + x + 1], dp[i][j] + inp[i + 1][x]);
            }
        }
    /*
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= p; j++)
            printf("%6d%c", dp[i][j], j == p ? '\n' : ' ');
    */

    return dp[n - 1][p];
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++)
        printf("Case #%d: %d\n", i, solve());

    return 0;
}
