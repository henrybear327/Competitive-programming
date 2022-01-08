#include <bits/stdc++.h>

using namespace std;

const char *dir = "RLDU";
int converted[51];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

char inp[51];
int ans = 0;
bool seen[9][9];

inline void dfs(int depth, int x, int y)
{
    if (depth == 48) {      // max depth
        if (x == 7 && y == 1) // reached destination
            ans++;
        return;
    }

    if (x == 7 && y == 1)
        return;

    /*
    // this is for some reason 0.3s slower
    int g1 = 0, g2 = 0;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (seen[xx][yy]) {
            continue;
        }

        if (i <= 1)
            g1++;
        else
            g2++;
    }

    if ((g1 == 2 && g2 == 0) || (g1 == 0 && g2 == 2)) {
        return;
    }
    */
    if (seen[x][y - 1] && seen[x][y + 1] && !seen[x - 1][y] && !seen[x + 1][y])
        return;
    if (seen[x - 1][y] && seen[x + 1][y] && !seen[x][y - 1] && !seen[x][y + 1])
        return;

    seen[x][y] = true;

    int idx = converted[depth];
    if (idx == 4 /*inp[depth] == '?'*/) {
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (seen[xx][yy])
                continue;

            dfs(depth + 1, xx, yy);
        }
    } else {
        int xx = x + dx[idx];
        int yy = y + dy[idx];

        if (seen[xx][yy])
            goto done;

        dfs(depth + 1, xx, yy);

        goto done;
    }

done:
    seen[x][y] = false;
}

int main()
{
    scanf("%s", inp);

    for (int i = 0; i < 48; i++) {
        converted[i] = 4;
        for (int j = 0; j < 4; j++) {
            if (dir[j] == inp[i]) {
                converted[i] = j;
                break;
            }
        }
    }

    memset(seen, false, sizeof(seen));
    for (int i = 0; i < 9; i++) {
        seen[i][0] = true;
        seen[0][i] = true;
        seen[8][i] = true;
        seen[i][8] = true;
    }

    dfs(0, 1, 1);
    printf("%d\n", ans);

    return 0;
}
