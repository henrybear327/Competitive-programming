#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    x--, y--;

    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) {
        g[i + 1].push_back(i);
        g[i].push_back(i + 1);
    }
    g[x].push_back(y);
    g[y].push_back(x);

    int ans[n] = {0};
    for (int i = 0; i < n; i++) {
        // bfs
        queue<int> q;
        q.push(i);
        bool used[n] = {false};
        int dist[n] = {0};
        used[i] = true;
        dist[i] = 0;
        while (q.size() > 0) {
            int cur = q.front();
            q.pop();

            for (auto v : g[cur]) {
                if (used[v])
                    continue;
                q.push(v);
                used[v] = true;
                dist[v] = dist[cur] + 1;
            }
        }

        for (int j = 0; j < n; j++) {
            ans[dist[j]]++;
        }
    }

    for (int i = 1; i <= n - 1; i++)
        printf("%d\n", ans[i] / 2);

    return 0;
}
