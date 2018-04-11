#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to, cost;
};

const int MAX_V = 333;
const int MAX_E = 5555;
const int INF = 0x3f3f3f3f;
int V, E;
Edge edges[MAX_E];
int d[MAX_V];

bool bellman_ford()
{
    fill(d, d + V, INF);

    d[0] = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            Edge &e = edges[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;

                if (i == V - 1) // negative cycle
                    return true;
            }
        }
    }

    return false;
}

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    V = n;
    E = m;
    for (int i = 0; i < m; i++) {
        int f, t, c;
        scanf("%d %d %d", &f, &t, &c);
        f--;
        t--;
        edges[i] = Edge{f, t, c};
    }

    printf("%s\n", bellman_ford() ? "No" : "Yes");
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();

    return 0;
}
