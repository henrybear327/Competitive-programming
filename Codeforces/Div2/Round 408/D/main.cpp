#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<ii> g[300010];

int main()
{
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);

    // Can't come up with the solution using DFS QAQ
    queue<ii> q;
    int par[300010];
    memset(par, -1, sizeof(par));
    bool police[300010] = {false};
    for (int i = 0; i < k; i++) {
        int pos;
        scanf("%d", &pos);

        if (police[pos] == false) {
            q.push(ii(pos, 0));
            par[pos] = 0;
            police[pos] = true;
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(ii(v, i));
        g[v].push_back(ii(u, i));
    }

    set<int> ans;
    while (q.empty() == false) {
        ii cur = q.front();
        int u = cur.first;
        int step = cur.second;
        q.pop();

        if (step > d)
            continue;

        for (auto v : g[u]) {
            if (v.first == par[u])
                continue;

            if (par[v.first] != -1) {
                ans.insert(v.second);
            } else {
                q.push(ii(v.first, step + 1));
                par[v.first] = u;
            }
        }
    }

    printf("%d\n", (int)ans.size());
    for (auto i : ans)
        printf("%d ", i);

    return 0;
}
