#include <cstdio>
#include <cstring>

const int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
// stupid direction error

int record[20][20];
int maze[20][20];
int n;

#define VISITED 5
#define PATH 4
#define WALL 1
#define ROAD 0

bool flag = 0;
void dfs(int x, int y)
{
    record[x][y] = VISITED;

    if (x == n - 2 && y == n - 2) {
        record[x][y] = PATH;
        flag = 1;
        return;
    }

    for (int i = 0; i < 4 && flag == 0; i++) {
        int a = x + dir[i][0], b = y + dir[i][1];
        if (maze[a][b] == 0 && (0 <= a && a < n && 0 <= b && b < n) &&
            record[a][b] != VISITED) {
            dfs(a, b);
        }
    }

    if (flag) {
        record[x][y] = PATH;
    }
}

int main()
{
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &maze[i][j]);
                record[i][j] = maze[i][j];
            }
        }

        flag = 0;
        dfs(1, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (record[i][j] == WALL)
                    printf("%c", '1');
                else if (record[i][j] == ROAD)
                    printf("%c", '0');
                else if (record[i][j] == PATH)
                    printf("%c", '#');
                else
                    printf("%c", '*');

                printf("%c", j != n - 1 ? ' ' : '\n');
            }
        }
    }

    return 0;
}
