#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    unordered_map<int, int> fcnt, ccnt;
    for (int i = 0; i < n * k; i++) {
        int num;
        scanf("%d", &num);
        ccnt[num]++;
    }

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        fcnt[num]++;
    }

    int h[k + 1];
    h[0] = 0;
    for (int i = 1; i <= k; i++)
        scanf("%d", &h[i]);

    int dp[n + 1][n * k + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n * k; j++)
            dp[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n * k; j++) {
            for (int x = 0; x <= k; x++) {
                if (j - x >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + h[x]);
            }
        }
    }

    int ans = 0;
    for (auto i : fcnt) {
        ans += dp[i.second][ccnt[i.first]];
    }
    printf("%d\n", ans);

    return 0;
}
