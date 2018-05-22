#include <bits/stdc++.h>

using namespace std;

#define EMPTY 0
#define WALL 1
#define VISITED 2

int n, m, query;
int g[1010][1010];

const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int DP[1010][1010];

void change_num(int x, int y, int cnt)
{
    DP[x][y] = cnt;
    for (int i = 0; i < 4; i++) {
        if (g[x + dir[i][0]][y + dir[i][1]] == VISITED) {
            g[x + dir[i][0]][y + dir[i][1]] = WALL;
            change_num(x + dir[i][0], y + dir[i][1], cnt);
        }
    }
}

int dfs(int x, int y, int cnt, bool state)
{
    g[x][y] = VISITED;
    for (int i = 0; i < 4; i++)
        if (g[x + dir[i][0]][y + dir[i][1]] == WALL)
            cnt++;

    for (int i = 0; i < 4; i++) {
        if (g[x + dir[i][0]][y + dir[i][1]] == EMPTY) {
            cnt = dfs(x + dir[i][0], y + dir[i][1], cnt, false);
        }
    }

    if (state) {
        change_num(x, y, cnt);
        return cnt;
    } else {
        return cnt;
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &query);

    for (int i = 0; i < n; i++) {
        char inp[2000];
        scanf("%s", inp);

        for (int j = 0; j < m; j++) {
            if (inp[j] == '.')
                g[i][j] = EMPTY;
            else if (inp[j] == '*')
                g[i][j] = WALL;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == EMPTY)
                dfs(i, j, 0, true);

    for (int i = 0; i < query; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%d\n", DP[x - 1][y - 1]);
    }

    return 0;
}
