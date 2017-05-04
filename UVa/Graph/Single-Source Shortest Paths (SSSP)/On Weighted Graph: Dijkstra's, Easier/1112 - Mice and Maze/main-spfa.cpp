#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int(x.size()))
const int MAX_N = 111;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> ii;

struct Edge {
    int to, w;

    Edge(int a, int b)
    {
        to = a;
        w = b;
    }
};

vector<Edge> g[MAX_N];

int n, e, t, m;
int d[MAX_N];
bool spfa(int V, int S)
{
    fill(d, d + V, INF);
    queue<int> q;
    vector<bool> inq(V, false);
    vector<int> cnt(V, 0);

    d[S] = 0;
    cnt[S]++;
    inq[S] = true;
    q.push(S);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = 0; i < sz(g[u]); i++) {
            const Edge &e = g[u][i];
            if (d[e.to] > d[u] + e.w) {
                d[e.to] = d[u] + e.w;
                if (++cnt[e.to] >= V) {
                    return true;
                }
                if (!inq[e.to]) {
                    inq[e.to] = true;
                    q.push(e.to);
                }
            }
        }
    }

    return false;
}

void solve()
{
    scanf("%d %d %d %d", &n, &e, &t, &m);

    for (int i = 0; i < n; i++)
        g[i].clear();

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;

        g[v].push_back(Edge(u, w)); // fuck this shit...
    }

    // get shortest path from e to all other vertex
    spfa(n, e - 1);

    // get number of vertex dist <= t
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (d[i] <= t)
            ans++;
    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
        if (ncase)
            printf("\n");
    }

    return 0;
}
