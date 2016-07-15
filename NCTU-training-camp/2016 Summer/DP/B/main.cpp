#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = (ll)1e8;

int main()
{
    int n1, n2, k1, k2;
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);

    ll dp[n1 + 1][n2 + 1][2];
    memset(dp, 0, sizeof(dp));

    // base case for test case 2 (2 3 1 2)
    /*
    1. row for n1, column for n2
    2. the 3rd dimension means ending with 1 or 2

    table for [.][.][0] (ending with 1)
        0   1	2   3
    0	0   0	0   0
    1	1
    2	0

    table for [.][.][1] (ending with 2)
        0   1	2   3
    0	0   1	1   0
    1	0
    2	0
    */
    dp[0][0][0] = dp[0][0][1] = 0;
    // if you don't set min(k1, n1), it'll overflow to the next row!!
    for (int i = 1; i <= min(k1, n1); i++)
        dp[i][0][0] = 1;
    for (int j = 1; j <= min(k2, n2); j++)
        dp[0][j][1] = 1;

    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++) {
            // calculate [i][j][0]
            for (int k = 1; k <= min(i, k1); k++) {
                dp[i][j][0] += dp[i - k][j][1];
                dp[i][j][0] %= M;
            }

            // calculate [i][j][1]
            for (int k = 1; k <= min(j, k2); k++) {
                dp[i][j][1] += dp[i][j - k][0];
                dp[i][j][1] %= M;
            }
        }

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++)
            printf("%lld ", dp[i][j][0]);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++)
            printf("%lld ", dp[i][j][1]);
        printf("\n");
    }

    printf("%lld\n", (dp[n1][n2][0] + dp[n1][n2][1]) % M);

    return 0;
}
