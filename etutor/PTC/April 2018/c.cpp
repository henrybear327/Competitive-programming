#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sumHeight(vector<vector<int>> &g, int p, int u, ll &ans)
{
    // printf("par %d cur %d\n", p + 1, u + 1);
    ll sum = 0;

    for (auto v : g[u]) {
        // printf("u = %d p = %d v = %d\n", u + 1, p + 1, v + 1);
        if (v == p)
            continue;
        sum = max(sum, sumHeight(g, u, v, ans) + 1);
    }

    // printf("u %d sum %d\n", u + 1, sum);
    ans += sum;
    return sum;
}

void dfs(int u, int height, vector<vector<int>> &g, vector<bool> &seen,
         int &mxH, int &who)
{
    if (seen[u])
        return;
    seen[u] = true;

    if (height > mxH) {
        mxH = height;
        who = u;
    }
    for (auto v : g[u]) {
        dfs(v, height + 1, g, seen, mxH, who);
    }
}

void cal(int u, int height, int p, vector<int> &dist, vector<vector<int>> &g)
{
    dist[u] = max(dist[u], height);
    for (auto v : g[u]) {
        if (v == p)
            continue;
        cal(v, height + 1, u, dist, g);
    }
}

ll sumEcc(vector<vector<int>> &g, int root)
{
    vector<int> dist(g.size(), 0);

    int who_root = -1;
    {
        vector<bool> seen(g.size(), false);
        int mxH = -1;
        dfs(root, 0, g, seen, mxH, who_root);

        // printf("furthest from root %d\n", who_root + 1);
        cal(who_root, 0, -1, dist, g);
    }

    int who_second = -1;
    {
        vector<bool> seen(g.size(), false);
        int mxH = -1;
        dfs(who_root, 0, g, seen, mxH, who_second);

        // printf("furthest from root %d\n", who_second + 1);
        cal(who_second, 0, -1, dist, g);
    }

    ll ans = 0;
    for (int i = 0; i < (int)g.size(); i++)
        ans += dist[i];
    return ans;
}

void solve()
{
    int n;
    scanf("%d", &n);

    // IO
    vector<vector<int>> g(n, vector<int>());
    vector<int> outDegree(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int p, u;
        scanf("%d %d", &p, &u);
        p--;
        u--;
        g[p].push_back(u);
        g[u].push_back(p);
        outDegree[u]++;
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (outDegree[i] == 0)
            root = i;
    }
    // printf("root %d\n", root + 1);

    ll h = 0;
    sumHeight(g, -1, root, h);
    printf("%lld %lld\n", h, sumEcc(g, root));
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();

    return 0;
}
