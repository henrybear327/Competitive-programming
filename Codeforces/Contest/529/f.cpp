#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;

struct Edge {
    int u, v;
    ll w;
};

struct UFDS {
    int par[200010];
    void init()
    {
        memset(par, -1, sizeof(par));
    }

    int root(int x)
    {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    bool same(int u, int v)
    {
        u = root(u);
        v = root(v);

        return u == v;
    }

    void merge(int u, int v)
    {
        if (same(u, v))
            return;
        u = root(u);
        v = root(v);

        if (par[u] > par[v])
            swap(u, v);

        par[u] += par[v];
        par[v] = u;
    }
} uf;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    ii inp[n];
    for (int i = 0; i < n; i++) {
        ll tmp;
        scanf("%lld", &tmp);
        inp[i] = {i, tmp};
    }
    sort(inp, inp + n,
    [](const ii &a, const ii &b) {
        return a.second < b.second;
    });

    vector<Edge> discount;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        u--;
        v--;

        discount.push_back({u, v, w});
    }
    sort(discount.begin(), discount.end(),
    [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    // Kruskal
    int cnt = n - 1;
    ll ans = 0;
    uf.init();

    int l = 0, r = l + 1;
    int idx = 0;
    while (cnt > 0) {
#if DEBUG
        printf("cnt = %d\n", cnt);
#endif

        // node sum
        ll nodeSum = LLONG_MAX;
        int un = -1, vn = -1;
        if (l < r && l <= n - 2) {
            nodeSum = inp[l].second + inp[r].second;
            un = inp[l].first;
            vn = inp[r].first;
        }
#if DEBUG
        printf("node %d %d %lld\n", un, vn, nodeSum);
#endif
        // edge discount
        ll edgeDiscount = LLONG_MAX;
        int ue = -1, ve = -1;
        if (idx < m) {
            edgeDiscount = discount[idx].w;
            ue = discount[idx].u;
            ve = discount[idx].v;
        }
#if DEBUG
        printf("edge %d %d %lld\n", ue, ve, edgeDiscount);
#endif

        if (nodeSum <= edgeDiscount) {
            if (uf.same(un, vn) == false) {
                uf.merge(un, vn);
                ans += nodeSum;
                cnt--;
            }
            r++;

            if (r >= n) {
                l++;
                r = l + 1;
            }
        } else { /* (nodeSum > edgeDiscount) */
            if (uf.same(ue, ve) == false) {
                uf.merge(ue, ve);
                ans += edgeDiscount;
                cnt--;
            }
            idx++;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
