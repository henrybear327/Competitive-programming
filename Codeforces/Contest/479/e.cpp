#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 200010;
vector<int> g[N];
bool seen[N];

// can also record the nodes visited on DFS
// and upon reading input we can calculate the deg
// so we can check afterwards

bool isCycle;
bool error;
void dfs(int u, int p)
{
    if (seen[u]) {
        isCycle = true; // step on visited node -> cycle
        return;
    }
    seen[u] = true;

    // nodes on the loop must all have deg = 2
    if (g[u].size() != 2) 
        error = true;
    for (auto v : g[u]) {
        if (v == p)
            continue;
        dfs(v, u);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(seen, false, sizeof(bool) * n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i] == false) {
            isCycle = false;
            error = false;
            dfs(i, -1);

            if (isCycle && error == false) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
