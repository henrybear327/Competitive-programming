#include <cstdio>
#include <cstdlib>
#include <cstring>

#define light 1
#define dark 0

int graph[110][110];
int n, m;

const int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool check(int x, int y)
{
    for (int i = 0; i < 4; i++) {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];
        if ((0 <= x1 && x1 < n) && (0 <= y1 && y1 < m)) {
            if (graph[x1][y1] == 0)
                return true;
        }
    }

    return false;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &graph[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 1 && check(i, j) == true) {
                    printf("0 ");
                } else {
                    printf("_ ");
                }
            }
            printf("\n");
        }

        if (ncase)
            printf("\n");
    }

    return 0;
}
