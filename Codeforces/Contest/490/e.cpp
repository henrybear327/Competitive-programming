#include <bits/stdc++.h>

/*
7 8 1
2 1
3 2
4 3
2 4
5 4
6 5
5 7
7 6

The idea is that after we explore all nodes that can be reached by s
For every unvisited nodes, we visit them, and use DFS to mark all 
connected nodes
Then, we connect s to the last visited nodes, then second-to-last...
*/

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

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        g[u].push_back(v);
    }

    bool seen[n];
    memset(seen, false, sizeof(seen));
    dfs(s, seen);

    int ans = 0;

    bool bak[n];
    memcpy(bak, seen, sizeof(seen));
    vector<int> q;
    for (int i = 0; i < n; i++)
        if (seen[i] == false) {
            q.push_back(i);
            dfs(i, seen);
        }

    memcpy(seen, bak, sizeof(bak));
    while (q.size() > 0) {
        int cur = q.back();
        q.pop_back();

        if (seen[cur] == false) {
            ans++;
            dfs(cur, seen);
        }
    }

    printf("%d\n", ans);

    return 0;
}
