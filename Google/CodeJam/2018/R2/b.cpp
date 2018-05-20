#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int dp[555][555];

int solve()
{
    memset(dp, 0, sizeof(dp));

    int n, m;
    scanf("%d %d", &n, &m);

    // f[i][v][u]=max{f[i-1][v][u],f[i-1][v-a[i]][u-b[i]]+w[i]}
    // 設 f[i][v][u]表示前 i 件物品付出兩種代價分別為 v 和 u 時可獲得的最大價值。

    vector<ii> items;
    for (int i = 0; i <= 40; i++)
        for (int j = 0; j <= 40; j++) {
            if (i == 0 && j == 0)
                continue;
            // printf("%d %d\n", i, j);
            items.push_back(ii(i, j));
        }

    for (int i = 0; i < (int)items.size(); i++) {
        for (int v = n; v >= 0; v--) {
            if (v - items[i].first < 0)
                continue;
            for (int u = m; u >= 0; u--) {
                if (u - items[i].second >= 0)
                    dp[v][u] =
                        max(dp[v][u], dp[v - items[i].first][u - items[i].second] + 1);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %d\n", i, solve());
    }

    return 0;
}