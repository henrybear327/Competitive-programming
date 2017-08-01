#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int target;
    scanf("%d", &target);

    int n;
    scanf("%d", &n);

    int c[n], sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        sum += c[i];
    }

    int dp[sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (dp[j] > 0 && j + c[i] <= sum) {
                if (dp[j + c[i]] > 0)
                    dp[j + c[i]] = min(dp[j + c[i]], dp[j] + 1);
                else
                    dp[j + c[i]] = j == 0 ? 1 : dp[j] + 1;
            }
        }
    }

    for (int i = target; i <= sum; i++) {
        if (dp[i] > 0) {
            printf("%d %d\n", i, dp[i]);
            break;
        }
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        solve();
    }

    return 0;
}