#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct UFDS {
    int par[100010];
    void init()
    {
        memset(par, -1, sizeof(par));
    }

    int root(int x)
    {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    ll merge(int x, int y)
    {
        x = root(x);
        y = root(y);

        if (x == y)
            return 0;

        if (par[x] > par[y])
            swap(x, y);

        ll ret = 1LL * par[x] * par[y];
        par[x] += par[y];
        par[y] = x;

        return ret;
    }

} uf;

int main()
{
    uf.init();
    int n, m;
    scanf("%d %d", &n, &m);

    ll ans = 1LL * n * (n - 1) / 2;
    vector<ll> ret;
    vector<ii> inp;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        inp.push_back({u, v});
    }

    for (int i = m - 1; i >= 0; i--) {
        ret.push_back(ans);
        ans -= uf.merge(inp[i].first, inp[i].second);
    }

    reverse(ret.begin(), ret.end());
    for (auto i : ret)
        printf("%lld\n", i);

    return 0;
}
