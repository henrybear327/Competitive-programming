#include <bits/stdc++.h>

using namespace std;

int ans, town, wilderness;
int v[510][510];
char g[510][510];

int n, m;
int a, b;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool bounded(int x, int y)
{
    return (0 <= x && x < n) && (0 <= y && y < m);
}

void dfs(int x, int y, int step)
{
    v[x][y] = 1;
    if (x == n - 1 && y == m - 1) {
        ans = min(ans, town * b + wilderness * a);
        v[x][y] = 0;
        return;
    }

    if (step % 2 == 1)
        town++;
    else
        wilderness++;

    for (int i = 0; i < n; i++) {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];

        if (bounded(x1, y1) && v[x1][y1] == 0 && g[x1][y1] == '.') {
            dfs(x1, y1, step + 1);
        }
    }
    v[x][y] = 0;
    if (step % 2 == 1)
        town--;
    else
        wilderness--;
}

int main()
{
    while (scanf("%d %d", &m, &n) == 2) {
        scanf("%d %d", &a, &b);
        town = 0;
        wilderness = 0;
        ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }

        memset(v, 0, sizeof(v));
        dfs(0, 0, 1);

        if (ans == INT_MAX)
            printf("IMPOSSIBLE\n");
        else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
