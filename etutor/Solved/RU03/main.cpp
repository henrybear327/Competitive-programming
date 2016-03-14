#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

enum type { WALL, WATER };

int row, col;
int g[410][410];

bool in_bound(int i, int j)
{
    return (0 <= i && i < row) && (0 <= j && j < col);
}

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int cnt;
void dfs(int x, int y)
{
    cnt++;
    g[x][y] = WALL;
    for (int i = 0; i < 4; i++) {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];

        if (in_bound(x1, y1) == true && g[x1][y1] == WATER) {
            dfs(x1, y1);
        }
    }
}

int main()
{
    while (scanf("%d %d", &row, &col) == 2) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int tmp;
                scanf("%d", &tmp);

                g[i][j] = tmp == 1 ? WATER : WALL;
            }
        }

        vector<int> ans;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cnt = 0;
                if (g[i][j] == WATER) {
                    dfs(i, j);
                    ans.push_back(cnt);
                }
            }
        }

        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());

        for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
            printf("%d\n", *it);
    }

    return 0;
}
