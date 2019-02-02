#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Edge {
    int u, v, w;
};

vector<Edge> g;

const int N = 200010;

struct UFDS {
    int par[N];
    void init()
    {
        memset(par, -1, sizeof(par));
    }

    int root(int u)
    {
        return par[u] < 0 ? u : par[u] = root(par[u]);
    }

    bool merge(int x, int y) // ret true if do merge shits
    {
        x = root(x);
        y = root(y);

        if (x == y)
            return false;

        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;

        return true;
    }
} uf;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        g.push_back(Edge{u, v, w});
    }

    if (m > 0) {
        sort(g.begin(), g.end(),
        [](const Edge &a, const Edge &b) {
            return a.w < b.w;
        });

        uf.init();

        int ans = 0, good = 0, cur = g[0].w;
        vector<int> cand;
        for (int i = 0; i <= m; i++) {
            // printf("i = %d\n", i);
            if (i < m && g[i].w == cur) {
                if (uf.root(g[i].u) == uf.root(g[i].v)) // this edge won't do any good
                    continue;

                cand.push_back(i);
            } else {
                for (auto j : cand) {
                    int u = g[j].u;
                    int v = g[j].v;
                    // printf("%d %d %d\n", u, v, g[j].w);

                    if (uf.merge(u, v))
                        good++;
                }
                ans += cand.size() - good;
                cand.clear();

                if (i == m)
                    break;
                cur = g[i].w;
                i--;
                good = 0;
            }
        }
        printf("%d\n", ans);
    } else {
        printf("%d\n", 0);
    }

    return 0;
}
