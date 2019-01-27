#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

bool dirty;
vector<ii> g[11111];

int dfs(int u, int p, int &ans)
{
    int mx = 0;
    for (auto v : g[u]) {
        if (v.first == p)
            continue;
        int cur = dfs(v.first, u, ans) + v.second;
        ans = max(ans, cur + mx);
        mx = max(mx, cur);
    }

    return mx;
}

void solve()
{
    int ans = 0;
    dfs(0, -1, ans);

    for (int i = 0; i < 11111; i++)
        g[i].clear();

    printf("%d\n", ans);
}

int main()
{
    char inp[111];
    dirty = false;
    while (fgets(inp, 111, stdin) != NULL) {
        if (inp[0] == '\n' || inp[0] == '\r') {
            solve();
            continue;
        }

        dirty = true;
        int u, v, w;
        sscanf(inp, "%d %d %d", &u, &v, &w);
        u--;
        v--;
        g[u].push_back(ii(v, w));
        g[v].push_back(ii(u, w));
    }

    if (dirty)
        solve();

    return 0;
}
