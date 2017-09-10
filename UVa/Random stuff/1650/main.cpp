#include <bits/stdc++.h>

using namespace std;

int dp[1111][1111];
char inp[1111];

const int MOD = 1000000007;

void solve()
{
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;

    int len = strlen(inp + 2);
    // printf("%s %d\n", inp + 2, len);
    for (int i = 2; i < len + 2; i++) {
        /*
        for(int j = 1; j <= i; j++) {
            if(inp[i] == 'I') {
                for(int k = 1; k < j; k++) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            } else if(inp[i] == 'D') {
                for(int k = j; k < i; k++) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            } else {
                for(int k = 1; k < i; k++) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            }
        }
        */
        if (inp[i] == 'I') {
            for (int j = 1; j <= i; j++) {
                dp[i][j] += dp[i][j - 1] + dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
        } else if (inp[i] == 'D') {
            for (int j = i; j >= 1; j--) {
                dp[i][j] += dp[i - 1][j] + dp[i][j + 1];
                dp[i][j] %= MOD;
            }
        } else {
            int dp_I[1111];
            int dp_D[1111];
            memset(dp_I, 0, sizeof(dp_I));
            memset(dp_D, 0, sizeof(dp_D));

            for (int j = 1; j <= i; j++) {
                dp_I[j] += dp_I[j - 1] + dp[i - 1][j - 1];
                dp_I[j] %= MOD;
            }

            for (int j = i; j >= 1; j--) {
                dp_D[j] += dp[i - 1][j] + dp_D[j + 1];
                dp_D[j] %= MOD;
            }

            for (int j = 1; j <= i; j++) {
                dp[i][j] = (dp[i][j] + (dp_D[j] + dp_I[j]) % MOD) % MOD;
            }
        }
    }

#if DEBUG
    for (int i = 0; i < len + 2; i++)
        for (int j = 0; j < len + 2; j++) {
            printf("%d%c", dp[i][j], j == len + 1 ? '\n' : ' ');
        }
#endif

    int ans = 0;
    for (int i = 1; i <= len + 1; i++) {
        // printf("i = %d: %d\n", i, dp[len + 1][i]);
        ans += dp[len + 1][i];
        ans %= MOD;
    }
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%s", inp + 2) == 1)
        solve();

    return 0;
}
