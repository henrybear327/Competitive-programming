#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> g[22222];
void add_edge(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

bool seen[22222];
int mx_size[22222], num[22222];
int n;
void dfs(int u, int p)
{
    if (seen[u])
        return;
    seen[u] = true;

    num[u] = 1; // base case, see line 33

    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];

        if (v == p)
            continue;
        dfs(v, u);

        mx_size[u] =
            max(mx_size[u], num[v]); // the subtree size below the current node u
        num[u] += num[v]; // the nodes visited so far under the current node u (including u itself)
    }

    mx_size[u] = max(mx_size[u], n - num[u]); // the "subtree" above the current node u under current traversal sequence
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        scanf("%d", &n);

        for (int i = 0; i <= n; i++)
            g[i].clear();

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

            add_edge(u, v);
        }

        memset(seen, false, sizeof(seen));
        memset(mx_size, 0, sizeof(mx_size));
        memset(num, 0, sizeof(num));
        dfs(1, -1);

        int mn = 22222, idx = 0;
        for (int i = 1; i <= n; i++) {
            if (mn > mx_size[i]) {
                idx = i;
                mn = min(mn, mx_size[i]);
            }

            // printf("%d %d\n", i, mx_size[i]);
        }

        printf("%d %d\n", idx, mn);
    }

    return 0;
}
