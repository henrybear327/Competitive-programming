#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<ii> g[111];
int spfa(int s, int t)
{
    long long d[111];
    fill(d, d + 111, INT_MAX);
    d[s] = 0; // init yourself

    priority_queue<ii> pq;
    pq.push(ii(0, s));
    while (!pq.empty()) {
        ii cur = pq.top();
        pq.pop();

        int dd = cur.first, u = cur.second;

        if (d[u] < dd)
            continue;

        for (auto i : g[u]) {
            int v = i.first, w = i.second;
            if (dd + w < d[v]) {
                d[v] = dd + w;
                pq.push(ii(d[v], v)); // stupid...
            }
        }
    }

    return d[t];
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        for (int i = 0; i < 111; i++)
            g[i].clear();
        int n, e, t, m;
        scanf("%d %d %d %d", &n, &e, &t, &m);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            g[u].push_back(ii(v, w));
        }

        int ans = 0; // self
        for (int i = 1; i <= n; i++) {
            if (spfa(i, e) <= t)
                ans++;
        }
        printf("%d\n", ans);

        if (ncase != 0)
            printf("\n");
    }

    return 0;
}
