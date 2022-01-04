#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, _w;
    scanf("%d %d", &n, &_w);

    long long int dp[_w + 1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int w, v;
        scanf("%d %d", &w, &v);

        for (int j = _w; j >= 0; j--) {
            if (j - w >= 0) {
                if (dp[j - w] != -1) {
                    dp[j] = max(dp[j], dp[j - w] + v);
                }
            } else {
                break;
            }
        }
    }

    long long int ret = 0;
    for (int i = 0; i <= _w; i++) {
        ret = max(ret, dp[i]);
    }
    printf("%lld\n", ret);

    return 0;
}
