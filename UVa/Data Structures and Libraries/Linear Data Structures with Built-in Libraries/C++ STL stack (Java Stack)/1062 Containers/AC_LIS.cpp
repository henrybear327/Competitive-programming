#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    char inp[10000];
    int ncase = 1;
    while (scanf("%s", inp) == 1 && strcmp(inp, "end") != 0) {
        int len = strlen(inp), dp[10010];
        fill(dp, dp + len, 1);

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (inp[j] > inp[i]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < len; i++)
            ans = max(ans, dp[i]);
        printf("Case %d: %d\n", ncase++, ans);
    }

    return 0;
}
