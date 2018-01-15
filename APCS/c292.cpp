#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0, -1, 0, 1}; // up right down left
const int dy[4] = {-1, 0, 1, 0};

int main()
{
    int n;
    scanf("%d", &n);
    int dir;
    scanf("%d", &dir); // left, up, right, down

    int inp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &inp[i][j]);

    int step = 1, stepCnt = 0;
    int cnt = 1;
    int x = n / 2, y = n / 2;
    printf("%d", inp[x][y]);
    while (cnt < n * n) {
        for (int i = 0; i < step; i++) {
            x += dx[dir];
            y += dy[dir];
            printf("%d", inp[x][y]);
            cnt++;
            if (i == step)
                break;
            if (cnt == n * n)
                break;
        }

        if (cnt == n * n)
            break;

        stepCnt++;
        if (stepCnt % 2 == 0)
            step++;

        dir++;
        dir %= 4;
    }

    return 0;
}
