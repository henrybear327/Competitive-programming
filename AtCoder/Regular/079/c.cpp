#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> g[222222];

int dist[222222];

typedef pair<int, int> ii; // dist, who

const int MAX = 0x3f3f3f3f;
void dijkstra()
{
    fill(dist, dist + 222222, MAX);

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[1] = 0;
    pq.push(ii(0, 1));

    while (pq.empty() == false) {
        ii cur = pq.top();
        pq.pop();

        int u = cur.second;
        int d = cur.first;

        if (d > dist[u])
            continue;

        for (auto v : g[u]) {
            if (dist[v] > d + 1) {
                dist[v] = d + 1;
                pq.push(ii(dist[v], v));
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    //     printf("%d%c", dist[i], i == n ? '\n' : ' ');
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dijkstra();

    printf("%s\n", dist[n] == 2 ? "POSSIBLE" : "IMPOSSIBLE");

    return 0;
}