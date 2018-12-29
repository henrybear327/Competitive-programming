#include <bits/stdc++.h>

using namespace std;

// 0:52 1WA 1AC

typedef long long ll;

struct Edge {
    int u, v, w;
};

struct UFDS {
    int par[555];
    void init()
    {
        memset(par, -1, sizeof(par));
    }

    int root(int x)
    {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    void merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;

        if (par[x] > par[y])
            swap(x, y);

        par[x] += par[y];
        par[y] = x;
    }
} uf;

const int MOD = 65537;

void solve()
{
    uf.init();

    int n, m;
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0)
        exit(0);

    vector<Edge> inp;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        inp.push_back(Edge{u, v, w});
    }

    sort(inp.begin(), inp.end(),
    [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    int cnt = 0;
    ll ans = 1;
    for (int i = 0; i < m; i++) {
        if (uf.root(inp[i].u) == uf.root(inp[i].v))
            continue;
        uf.merge(inp[i].u, inp[i].v);
        cnt++;
        ans = ans * inp[i].w % MOD;

        if (cnt == n - 1)
            break;
    }

    printf("%lld\n", ans);
}

int main()
{
    while (1)
        solve();

    return 0;
}
