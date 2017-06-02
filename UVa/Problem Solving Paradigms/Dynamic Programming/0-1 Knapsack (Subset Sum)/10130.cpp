#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int knapsack(vector<ii> &items, int total)
{
    int dp[items.size() + 1][total + 1];
    memset(dp, 0, sizeof(dp[0]));

    for (int i = 1; i <= (int)items.size(); i++) {
        int w = items[i - 1].first;
        int p = items[i - 1].second;

        for (int j = 0; j <= total; j++) {
            if (j - w < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + p);
        }
    }

    return dp[items.size()][total];
}

void solve()
{
    int n;
    scanf("%d", &n);

    vector<ii> items;
    for (int i = 0; i < n; i++) {
        int p, w;
        scanf("%d %d", &p, &w);

        items.push_back(ii(w, p));
    }

    int g, res = 0;
    scanf("%d", &g);
    for (int i = 0; i < g; i++) {
        int w;
        scanf("%d", &w);

        res += knapsack(items, w);
    }

    printf("%d\n", res);
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
