#include <cstdio>
#include <cstring>

char map[1000][1000];
char square[1000][1000];

void rotate(int n)
{
    char tmp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[j][n - i - 1] = square[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = tmp[i][j];
}

int count(int N, int n)
{
    int cnt = 0;
    for (int i = 0; i < N - n + 1; i++) {
        for (int j = 0; j < N - n + 1; j++) {
            if (map[i][j] == square[0][0]) {
                bool flag = true;
                for (int x = 0; x < n && flag; x++) {
                    for (int y = 0; y < n && flag; y++) {
                        if (square[x][y] != map[i + x][j + y])
                            flag = false;
                    }
                }
                if (flag)
                    cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    int N, n;
    while (scanf("%d %d", &N, &n) == 2 && (N || n)) {
        getchar();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                scanf("%c", &map[i][j]);
            getchar();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                scanf("%c", &square[i][j]);
            getchar();
        }

        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                printf("%d", count(N, n));
            } else {
                rotate(n);
                printf(" %d", count(N, n));
            }
        }
        printf("\n");
    }

    return 0;
}
