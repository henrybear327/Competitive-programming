#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1000;

ll solve()
{
    int n;
    scanf("%d", &n);

    vector<ii> g[N];
    int deg[N] = {0};
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        u--;
        v--;

        g[u].push_back({v, c});
        g[v].push_back({u, c});

        deg[u]++;
        deg[v]++;

        sum += c;
    }

    ll ans = LLONG_MAX;
    auto dfs = [&](auto self, int u, int p, ll cost) -> void {
        // observation 1)
        // the ending point is a leaf
        // the root to ending leaf will only be walked once, other edges wil be walked twice

        // observation 2)
        // the solution is the sum * 2 - longest path between root - leaf
        if (p != -1 && deg[u] == 1)
        {
            ans = min(ans, cost + (sum - cost) * 2);
        }

        for (auto &[v, c] : g[u])
        {
            if (v == p)
                continue;
            self(self, v, u, cost + c);
        }
    };

    for (int i = 0; i < n; i++) {
        dfs(dfs, i, -1, 0);
    }

    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %lld\n", i, solve());
    }

    return 0;
}
