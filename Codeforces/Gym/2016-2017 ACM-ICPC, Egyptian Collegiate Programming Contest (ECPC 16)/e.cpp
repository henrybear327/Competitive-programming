#include <bits/stdc++.h>

using namespace std;

#define N 100010
vector<int> g[N];

void solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        g[i].clear();

    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);

        int nxt = i + d;
        int pre = i - d;

        if (nxt < n)
            g[nxt].push_back(i);
        if (pre >= 0)
            g[pre].push_back(i);
    }

    queue<int> q;
    int dist[N];
    memset(dist, -1, sizeof(dist));
    dist[n - 1] = 0;
    q.push(n - 1);

    while (q.empty() == false) {
        int u = q.front();
        q.pop();

        for (auto v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", dist[i]);
}

int main()
{
    freopen("jumping.in", "r", stdin);

    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
