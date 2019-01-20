#include <bits/stdc++.h>

using namespace std;

const int N = 5555;
vector<int> g[N];

void dfs(int u, bool seen[])
{
    if (seen[u])
        return;
    seen[u] = true;

    for (auto v : g[u])
        dfs(v, seen);
}

int main()
{
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    s--;

    int deg[n];
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;

        g[u].push_back(v);

        deg[v]++;
    }

    bool seen[n];
    memset(seen, false, sizeof(seen));
    dfs(s, seen);

    int ans = 0;

    // case deg = 0, head of linear
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (seen[i] == false && deg[i] == 0)
            q.push(i);

    while (q.size() > 0) {
        int cur = q.front();
        q.pop();

        dfs(cur, seen);
        ans++;
    }

    // case deg >= 1, cycle
    for (int i = 0; i < n; i++) {
        if (seen[i] == false) {
            ans++;
            dfs(i, seen);
        }
    }

    printf("%d\n", ans);

    return 0;
}
