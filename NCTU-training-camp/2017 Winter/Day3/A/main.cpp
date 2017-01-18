#include <bits/stdc++.h>

using namespace std;

int dp[333][333];
int pre[333];

int get(int l, int r) // [l, r]
{
    if (l > r)
        return 0;
    return pre[r] - pre[l - 1];
}

int solve(int l, int r) // [l, r]
{
    // printf("l %d r %d\n", l, r);

    if (l >= r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int mn = INT_MAX;
    for (int i = l; i <= r; i++) {
        // enumerate all roots
        int resL = solve(l, i - 1);
        int resR = solve(i + 1, r);

        int res = resL + get(l, i - 1) + resR + get(i + 1, r);
        mn = min(mn, res);
    }

    return (dp[l][r] = mn);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &pre[i]);
            pre[i] += pre[i - 1];
        }
        // for(int i = 0; i <= n; i++)
            //printf("%d %d\n", i, pre[i]);

        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(1, n));
    }

    return 0;
}
