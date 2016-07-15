#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 100;
const ll MOD = 1e8;

int N0, N1, K0, K1;
ll dp[MAX_N + 1][MAX_N + 1][2];

int main()
{
    scanf("%d %d %d %d", &N0, &N1, &K0, &K1);

    memset(dp, 0, sizeof(dp));

    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= min(N0, K0); i++) {
        dp[i][0][0] = 1;
    }
    for (int j = 1; j <= min(N1, K1); j++) {
        dp[0][j][1] = 1;
    }

    for (int i = 1; i <= N0; i++) {
        for (int j = 1; j <= N1; j++) {
            // dp[i][j][0] = sum(dp[i - k][j][1] for x in [1, min(i, K0)])
            for (int x = 1; x <= min(i, K0); x++) {
                dp[i][j][0] += dp[i - x][j][1];
                dp[i][j][0] %= MOD;
            }

            // dp[i][j][1] = sum(dp[i][j - x][0] for x in [1, min(j, K1)])
            for (int x = 1; x <= min(j, K1); x++) {
                dp[i][j][1] += dp[i][j - x][0];
                dp[i][j][1] %= MOD;
            }
        }
    }

    printf("%lld\n", (dp[N0][N1][0] + dp[N0][N1][1]) % MOD);

    return 0;
}
