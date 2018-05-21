#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[100010][555];
const ll oo = 0x3f3f3f3f3f3f3f3f;

int solve()
{
    int n;
    scanf("%d", &n);

    ll w[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%lld", &w[i]);

    // DP[i][j] = k
    // min weight sum = picking from ants [0, i], and we use only j of them
    for (int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + 555, oo);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j < 555; j++) {
            if (dp[i - 1][j - 1] <= 6LL * w[i]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + w[i]);
            }

            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 555 - 1; i >= 0; i--)
        if (dp[n][i] != oo)
            return i;
    return 0;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
}
