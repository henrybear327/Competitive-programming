#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100;
const int INF = 0x3f3f3f3f;
int V, E;
vector<int> g[MAX_V];
int deg[MAX_V];

int main()
{
    while (scanf("%d %d", &V, &E)) {
        if (V == 0 && E == 0)
            break;

        memset(deg, 0, sizeof(deg));
        for (int v = 0; v < 100; v++) {
            g[v].clear();
        }

        for (int i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[v]++;
            deg[u]++;
        }

        for (int i = 0; i < E; i++) {
            // find v with min deg and with edge
            int vert = -1, d = INF;
            for (int v = 0; v < V; v++) {
                if (g[v].size() > 0 && deg[v] < d) {
                    d = deg[v];
                    vert = v;
                }
            }

            int other = g[vert].back();
            g[vert].pop_back();

            // printf("%d, %d\n", vert, other);

            auto it = find(g[other].begin(), g[other].end(), vert);
            g[other].erase(it);

            deg[other]--;
        }

        int MM = -1, mm = INF;
        for (int v = 0; v < V; v++) {
            MM = max(MM, deg[v]);
            mm = min(mm, deg[v]);
        }

        printf("%d %d\n", mm, MM);
    }
    return 0;
}
