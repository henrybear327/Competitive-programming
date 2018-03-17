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
}

void prim()
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, 0));
    ll ans = 0;
    bool used[N] = {false};
    while (pq.size() > 0) {
        ll w = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (used[u])
            continue;
        used[u] = true;
        ans += w;

        for (auto nxt : g[u]) {
            ll vw = nxt.second;
            ll v = nxt.first;

            if (used[v] == false)
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
