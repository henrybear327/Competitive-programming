#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, _w;
    scanf("%d %d", &n, &_w);

    // we enumerate on all possible values
    // dp[items][value] = min weight to achieve the value
    // using the min weight guarantees that we can add new items, if possible
    long long int dp[100010];
    for (int i = 0; i < 100010; i++)
        dp[i] = LLONG_MAX;

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int w, v;
        scanf("%d %d", &w, &v);

        for (int j = 100000; j >= 0; j--) {
            if (j - v >= 0) {
                if (dp[j - v] != LLONG_MAX && dp[j - v] + w <= _w) {
                    dp[j] = min(dp[j], dp[j - v] + w);
                }
            } else {
                break;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i <= 100000; i++) {
        if (dp[i] != LLONG_MAX)
            ret = i;
    }
    printf("%d\n", ret);

    return 0;
}
