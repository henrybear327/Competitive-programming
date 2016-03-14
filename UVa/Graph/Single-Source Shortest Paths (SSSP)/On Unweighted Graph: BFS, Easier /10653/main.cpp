#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef struct coor {
    int x, y;
} Coor;

int main()
{
    int row, column;
    while (scanf("%d %d", &row, &column) == 2 && !(row == 0 && column == 0)) {
        int map[row][column];
        memset(map, 0, sizeof(map));

        int cases;
        scanf("%d", &cases);
        while (cases--) {
            int row, cnt;
            scanf("%d %d", &row, &cnt);
            while (cnt--) {
                int location;
                scanf("%d", &location);

                map[row][location] = 1;
            }
        }

        Coor s, e;
        scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);

        int visited[row][column];
        memset(visited, -1, sizeof(visited));

        queue<Coor> bfs;
        bfs.push(s);
        visited[s.x][s.y] = 0;

        const int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        while (bfs.size()) {
            Coor curr = bfs.front();
            bfs.pop();

            if (curr.x == e.x && curr.y == e.y)
                break;

            for (int i = 0; i < 4; i++) {
                if (curr.x + direction[i][0] >= 0 && curr.x + direction[i][0] < row &&
                    curr.y + direction[i][1] >= 0 &&
                    curr.y + direction[i][1] < column &&
                    map[curr.x + direction[i][0]][curr.y + direction[i][1]] == 0 &&
                    visited[curr.x + direction[i][0]][curr.y + direction[i][1]] == -1) {
                    Coor tmp = {curr.x + direction[i][0], curr.y + direction[i][1]};
                    bfs.push(tmp);
                    visited[tmp.x][tmp.y] = visited[curr.x][curr.y] + 1;
                }
            }

            /*
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    printf("%2d ", visited[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");
            */
        }

        printf("%d\n", visited[e.x][e.y]);
    }

    return 0;
}
