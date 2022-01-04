#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }

    int dp[n];
    dp[0] = 0;
    dp[1] = abs(inp[1] - inp[0]);

    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(inp[i] - inp[i - 1]),
                    dp[i - 2] + abs(inp[i] - inp[i - 2]));
    }

    printf("%d\n", dp[n - 1]);

    return 0;
}
