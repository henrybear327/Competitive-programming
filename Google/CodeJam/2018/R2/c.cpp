#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
void add_edge(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

int matching[222];
bool seen[222];

bool dfs(int u) // u must be unmatched node
{
    // printf("u %d\n", u);
    seen[u] = true;

    for (auto v : g[u]) {
        // 1. v is unmatched
        // 2. v is matched but not in current path, dfs
        if (matching[v] == -1 || (seen[matching[v]] == false && dfs(matching[v]))) {
            matching[u] = v;
            matching[v] = u;
            return true;
        }
    }

    return false;
}

int bipartite_matching(int n)
{
    int res = 0;
    memset(matching, -1, sizeof(matching));
    for (int i = 0; i < n; i++) {
        if (matching[i] == -1) {
            memset(seen, false, sizeof(seen));
            if (dfs(i))
                res++;
        }
    }

    return res;
}

int solve()
{
    int n;
    scanf("%d", &n);

    // read
    int inp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &inp[i][j]);
        }

    int stay = 0;
    for (int i = -n; i <= n; i++) {
        // printf("Now %d\n", i);
        if (i == 0)
            continue;

        g.clear();

        // build
        g = vector<vector<int>>(n * 2, vector<int>());
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                if (inp[j][k] == i) {
                    // row [0, n - 1]
                    // col [n, n + n - 1]
                    add_edge(j, n + k);
                }
            }

        // run
        stay += bipartite_matching(n * 2);
        // printf("%d %d\n", i, stay);
    }

    return n * n - stay;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %d\n", i, solve());
    }

    return 0;
}