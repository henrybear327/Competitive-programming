#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

struct {
    int par[111];
    void init()
    {
        memset(par, -1, sizeof(par));
    }

    int root(int x)
    {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    void merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;

        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }
} UFDS[111];

int main()
{
    for (int i = 0; i < 111; i++)
        UFDS[i].init();

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        UFDS[w].merge(u, v);
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        int ans = 0;
        for (int j = 1; j <= m; j++) {
            if (UFDS[j].root(u) == UFDS[j].root(v))
                ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
