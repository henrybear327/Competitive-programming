#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int inp[1000100];
int dp[1000100];

int main()
{
    int n;
    scanf("%d", &n);

    memset(inp, 0, sizeof(inp));

    int idx = INT_MIN;
    for (int i = 0; i < n; i++) {
        int pos, power;
        scanf("%d %d", &pos, &power);

        idx = max(idx, pos);

        inp[pos] = power;
    }

    for (int i = 0; i <= idx; i++) {
        if (inp[i] != 0) {
            if (i - inp[i] - 1 >= 0) {
                dp[i] = dp[i - inp[i] - 1] + 1;
            } else {
                dp[i] = 1;
            }
        } else {
            dp[i] = dp[i - 1];
        }
    }

    /*
    for (int i = 0; i <= idx; i++)
        printf("%d%c", inp[i], i == idx ? '\n' : ' ');

    for (int i = 0; i <= idx; i++)
        printf("%d%c", dp[i], i == idx ? '\n' : ' ');
    */

    int ans = INT_MAX;
    for (int i = 0; i <= idx; i++)
        ans = min(ans, n - dp[i]);

    printf("%d\n", ans);

    return 0;
}
