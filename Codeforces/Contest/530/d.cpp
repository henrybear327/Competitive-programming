#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 100010;
vector<int> g[N];
ll sum[N];
ll val[N];
int par[N];

void dfs(int u, int depth)
{
    if (depth % 2 == 0)
        val[u] = INT_MAX;
    for (auto v : g[u]) {
        if (depth % 2 == 0) {
            val[u] = min(val[u], sum[v] - sum[par[u]]);
        }
        dfs(v, depth + 1);
    }
    if (val[u] == INT_MAX) // even level leaf
        val[u] = 0;
}

bool error;
ll ans;
void dfs2(int u, ll tot)
{
    if (val[u] == -1) {
        val[u] = sum[u] - tot;
    }

    if (val[u] < 0)
        error = true;
    ans += val[u];

    for (auto v : g[u]) {
        dfs2(v, tot + val[u]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        int p;
        scanf("%d", &p);
        p--;

        par[i] = p;
        g[p].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lld", &sum[i]);
        val[i] = -1;
    }

    val[0] = sum[0];
    // get all ai for all even level nodes
    dfs(0, 1);
    error = false;
    ans = 0;
    dfs2(0, 0);

    if (error)
        printf("-1\n");
    else
        printf("%lld\n", ans);

    return 0;
}
