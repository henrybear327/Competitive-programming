#include <cstdio>
#include <cstdlib>
#include <cstring>

int map[20][20];
int path[20][20];
int row;

const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool ans_found;

void dfs(int x, int y)
{
    if (x == row - 2 && y == row - 2) {
        ans_found = true;
        return;
    }

    for (int i = 0; i < 4 && ans_found == false; i++) {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];
        if (path[x1][y1] == 0 && map[x1][y1] == 0 && (0 <= x1 && x1 < row) &&
            (0 <= y1 && y1 < row)) {
            path[x1][y1] = 1;
            dfs(x1, y1);
            if (ans_found == true)
                return;
            path[x1][y1] = 0;
        }
    }
}

int main()
{
    char input[100];
    memset(path, 0, sizeof(path));
    ans_found = false;

    row = 0;
    while (fgets(input, 100, stdin) != NULL) {
        int idx = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == '1' || input[i] == '0')
                map[row][idx++] = input[i] - '0';
        }

        row++;
    }

    path[1][1] = 1;
    dfs(1, 1);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (path[i][j] == 1)
                printf("%c%c", '#', j == row - 1 ? '\n' : ' ');
            else
                printf("%d%c", map[i][j], j == row - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
