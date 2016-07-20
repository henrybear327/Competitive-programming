#include <bits/stdc++.h>

using namespace std;

int par[111][111];
void init(int n)
{
    for (int i = 0; i < 111; i++)
        par[n][i] = -1;
}

int root(int n, int x)
{
    return par[n][x] < 0 ? x : par[n][x] = root(n, par[n][x]);
}

void merge(int n, int x, int y)
{
    x = root(n, x);
    y = root(n, y);
    if (x == y)
        return;

    if (par[n][x] > par[n][y])
        swap(x, y);
    par[n][x] += par[n][y];
    par[n][y] = x;
}

int main()
{
    for (int i = 0; i < 111; i++)
        init(i);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        merge(w, u, v);
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        int ans = 0;
        for (int j = 1; j <= m; j++) {
            if (root(j, u) == root(j, v))
                ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
