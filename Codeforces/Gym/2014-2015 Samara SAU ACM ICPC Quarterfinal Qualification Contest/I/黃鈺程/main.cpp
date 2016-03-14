#include <bits/stdc++.h>

using namespace std;

int N, M, K;

int color[1000];

bool connect[1000][1000];

bool dfs()
{
    int c = 1;
    for (int i = 0; i < N; i++) {
        if (color[i] == -1) {
            color[i] = c;
            for (int j = 0; j < N; j++) {
                if (!connect[i][j]) {
                    if (color[j] == -1 || color[j] == c)
                        color[j] = c;
                    else
                        return false;
                }
            }
            c++;
        }
    }

    return true;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    memset(color, -1, sizeof(color));

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        connect[x][y] = true;
        connect[y][x] = true;
    }

    if (dfs()) {
        for (int i = 0; i < N; i++) {
            if (color[i] > K) { // Your first mistake, not checking K!!
                printf("-1\n");
                return 0;
            }
        }

        for (int i = 0; i < N; i++) { // Your second mistake, you didn't check the
            // graph after filling in the colors
            for (int j = 0; j < N; j++) {
                if (connect[i][j]) {
                    if (color[i] == color[j]) {
                        printf("-1\n");
                        return 0;
                    }
                } else {
                    if (color[i] != color[j]) {
                        printf("-1\n");
                        return 0;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (i != 0)
                printf(" ");
            printf("%d", color[i]);
        }
        printf("\n");
    } else
        printf("-1\n");

    return 0;
}
