#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }

    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k && j + i < n; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(inp[i + j] - inp[i]));
        }
    }

    printf("%d\n", dp[n - 1]);

    return 0;
}
