#include <bits/stdc++.h>

using namespace std;

const int _MAX = INT_MAX;

int main()
{
    int n;
    scanf("%d", &n);

    int dp[8];
    fill(dp, dp + 8, INT_MAX);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        char inp[10];
        scanf("%s", inp);

        int len = strlen(inp);
        int mask = 0;
        for (int j = 0; j < len; j++) {
            if (inp[j] == 'A')
                mask |= (1 << 0);
            else if (inp[j] == 'B')
                mask |= (1 << 1);
            else
                mask |= (1 << 2);
        }

        dp[mask] = min(dp[mask], num);
    }

    /*
         for (int i = 0; i < 8; i++)
        printf("%d %d\n", i, dp[i]);
        */

    int ans = dp[7]; // WOW such a bug
    for (int i = 1; i < 8; i++)
        for (int j = i + 1; j < 8; j++) {
            int m = i | j;
            if (m == 7 && dp[i] != _MAX && dp[j] != _MAX)
                ans = min(ans, dp[i] + dp[j]);
            for (int k = j + 1; k < 8; k++) {
                m = i | j | k;
                if (m == 7 && dp[i] != _MAX && dp[j] != _MAX && dp[k] != _MAX)
                    ans = min(ans, dp[i] + dp[j] + dp[k]);
            }
        }

    printf("%d\n", ans == _MAX ? -1 : ans);
    return 0;
}
