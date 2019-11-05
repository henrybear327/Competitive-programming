#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f;

int main()
{
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);

    int dp[n][n];
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        u--, v--;
        dp[u][v] = dp[v][u] = c;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    int dp2[n][n];
    memset(dp2, INF, sizeof(dp2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dp[i][j] <= l)
                dp2[i][j] = 1;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k][j]);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;

        int ans;
        if (dp2[u][v] == 0x3f3f3f3f)
            ans = -1;
        else
            ans = dp2[u][v] - 1;
        printf("%d\n", ans);
    }

    return 0;
}
