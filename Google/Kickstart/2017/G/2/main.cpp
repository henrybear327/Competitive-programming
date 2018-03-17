#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 111;
vector<ii> g[N];

void build(ii inp[], int n)
{
    for (int i = 0; i < n; i++)
        g[i].clear();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j)
                continue;

            g[i].push_back(ii(j, inp[i].first ^ inp[j].second));
            g[i].push_back(ii(j, inp[i].second ^ inp[j].first));
            g[j].push_back(ii(i, inp[j].first ^ inp[i].second));
            g[j].push_back(ii(i, inp[j].second ^ inp[i].first));
        }
    }

#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        printf("u = %d: ", i);
        for (auto j : g[i]) {
            printf("(v = %lld, w = %lld) ", j.first, j.second);
        }
        puts("");
    }
#endif
}

struct UFDS {
    int par[N];
    void init()
    {
        memset(par, -1, sizeof(par));
    }

    ll root(ll u)
    {
        return par[u] < 0 ? u : par[u] = root(par[u]);
    }

    void merge(ll u, ll v)
    {
        u = root(u);
        v = root(v);

        if (u == v)
            return;

        if (par[u] > par[v])
            swap(u, v);

        par[u] += par[v];
        par[v] = u;
    }
} uf;

void prim()
{
    uf.init();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, 0));
    ll ans = 0;
    while (pq.size() > 0) {
        ll w = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (u != 0 && uf.root(u) == uf.root(0))
            continue;

        ans += w;
        uf.merge(0, u);

        for (auto nxt : g[u]) {
            ll vw = nxt.second;
            ll v = nxt.first;

            if (uf.root(u) != uf.root(v))
                pq.push(ii(vw, v));
        }
    }

    printf("%lld\n", ans);
}

void solve()
{
    int n;
    scanf("%d", &n);

    ii inp[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &inp[i].first);
    for (int i = 0; i < n; i++)
        scanf("%lld", &inp[i].second);

    build(inp, n);

    prim();
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
