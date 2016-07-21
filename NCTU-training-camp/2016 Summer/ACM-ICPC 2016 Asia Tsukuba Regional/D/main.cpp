#include <bits/stdc++.h>

using namespace std;

int n, inp[333];
int dp[333][333];

#define DEBUG 0

int solve(int l, int r) //[l, r]
{
#if DEBUG == 1
    printf("%d %d\n", l, r);
#endif
    if (!(0 <= l) || !(r < n) || l > r)
        return 0;
    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    if (l == r)
        return 0;
    if (r - l == 1) {
        if (abs(inp[r] - inp[l]) <= 1)
            return 1;
        else
            return 0;
    }

    int max3 = 0;
    for (int j = l; j <= r; j++) {
        for (int k = j + 1; k <= r; k++) {
            if (abs(inp[k] - inp[j]) <= 1 && solve(j + 1, k - 1) * 2 == k - j - 1)
                max3 = max(max3,
                           solve(l, j - 1) + 1 + solve(j + 1, k - 1) + solve(k + 1, r));
        }
    }

#if DEBUG == 1
    printf("%d %d mx %d\n", l, r, mx);
#endif
    return dp[l][r] = max3;
}

int main()
{
    while (scanf("%d", &n) == 1 && n) {
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++)
            scanf("%d", &inp[i]);

        printf("%d\n", solve(0, n - 1) * 2);
    }

    return 0;
}
