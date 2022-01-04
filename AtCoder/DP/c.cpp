#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int dp[n][3];
    memset(dp, 0, sizeof(dp));
    scanf("%d", &dp[0][0]);
    scanf("%d", &dp[0][1]);
    scanf("%d", &dp[0][2]);

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + b);
        dp[i + 1][2] = max(dp[i + 1][2], dp[i][0] + c);
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + a);
        dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + c);
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][2] + a);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][2] + b);
    }

    printf("%d\n", max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]));

    return 0;
}
