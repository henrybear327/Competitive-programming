#include <bits/stdc++.h>

using namespace std;

int mx = -1;
int cnt = 0;
bool seen[9][9];
char inp[9][12];
int xs, ys, xd, yd;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool check(int x, int y)
{
    return (0 <= x && x < 9) && (0 <= y && y < 9);
}

void dfs(int x, int y)
{
    cnt++;
    if (seen[x][y]) {
        cnt--;
        return;
    } else if (x == xd && y == yd) {
        mx = max(mx, cnt);
        cnt--;
        return;
    }
    seen[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (check(xx, yy) && (inp[xx][yy] == '+' || inp[xx][yy] == 'D') &&
            seen[xx][yy] == false)
            dfs(xx, yy);
    }

    seen[x][y] = false;
    cnt--;
}

void solve(int start)
{
    for (int i = start; i < 9; i++)
        fgets(inp[i], 12, stdin);

    xs = xd = ys = yd = -1;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            if (inp[i][j] == 'S') {
                xs = i;
                ys = j;
            } else if (inp[i][j] == 'D') {
                xd = i;
                yd = j;
            }
            seen[i][j] = false;
        }

    if (xs == -1 || xd == -1 || ys == -1 || yd == -1) {
        printf("-1\n");
        return;
    };

    mx = -1;
    cnt = 0;
    dfs(xs, ys);

    printf("%d\n", mx);
}

int main()
{
    bool first = true;
    while (fgets(inp[0], 12, stdin) != NULL) {
        if (first) {
            first = false;
            solve(1);
        } else
            solve(0);
    }

    return 0;
}
