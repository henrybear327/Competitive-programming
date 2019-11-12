#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // read
    int dp[1 << n];
    fill(dp, dp + (1 << n), INT_MAX);
    bool ok[1 << n] = {false};
    dp[0] = 0;
    ok[0] = true;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int mask = 0;
        for (int j = 0; j < b; j++) {
            int num;
            scanf("%d", &num);
            num--;
            mask |= (1 << num);
        }

        // printf("mask %d\n", mask);
        dp[mask] = min(dp[mask], a); // for each combination, use the min val one
        ok[mask] = true;
    }

    // solve
    int ans[1 << n];
    fill(ans, ans + (1 << n), INT_MAX);
    for (int i = 0; i < (1 << n); i++) {
        if (ok[i] == true) {
            // printf("ok %d\n", i);
            ans[i] = min(ans[i], dp[i]);
            for (int j = 0; j < (1 << n); j++) {
                if (ans[j] != INT_MAX) {
                    int target = (i | j);
                    // printf("%d %d %d %d\n", i, j, dp[i], ans[j]);
                    ans[target] = min(ans[target], dp[i] + ans[j]);
                }
            }
        }
    }
    printf("%d\n", ans[(1 << n) - 1] == INT_MAX ? -1 : ans[(1 << n) - 1]);

    /*
    for (int i = 0; i < (1 << n); i++) {
        printf("i = %d\n", i);
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                int a = (1 << j);
                int b = i ^ (1 << j);

                printf("%d %d %d %d\n", a, b, dp[a], dp[b]);
                if (ok[a] == false || ok[b] == false)
                    continue;
                dp[i] = min(dp[i], dp[a] + dp[b]);
                ok[i] = true;
            }
        }
    }
    printf("%d\n", ok[(1 << n) - 1] ? dp[(1 << n) - 1] : -1);
    */

    return 0;
}
