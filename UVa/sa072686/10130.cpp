#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    ii items[n]; // price, weight
    for (int i = 0; i < n; i++)
        scanf("%d %d", &items[i].first, &items[i].second);

    int m;
    scanf("%d", &m);
    int ans = 0;
    while (m--) {
        int w;
        scanf("%d", &w);

        int dp[w + 1];
        memset(dp, 0, sizeof(dp));

        for (int j = 0; j < n; j++) {
            for (int i = w; i >= 0; i--) {
                if (i + items[j].second <= w) {
                    dp[i + items[j].second] =
                        max(dp[i + items[j].second], dp[i] + items[j].first);
                }
            }
        }

        ans += dp[w];
    }

    printf("%d\n", ans);
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
