#include <cstdio>
#include <cstring>

int main()
{
    int node;
    while (scanf("%d", &node) == 1 && node) {
        int g[110][110];
        memset(g, 0, sizeof(g));

        for (int i = 1; i <= node; i++) {
            for (int j = i + 1; j <= node; j++) {
                int tmp;
                scanf("%d", &tmp);

                g[i][j] = g[j][i] = tmp;
            }
        }

        for (int i = 1; i <= node; i++) {
            for (int j = 1; j <= node; j++) {
                if (g[i][j]) {
                    for (int k = 1; k <= node; k++) {
                        if (k != i && g[j][k] && g[k][i]) {
                            g[j][k] = g[k][j] = 2;
                            g[k][i] = g[i][k] = 2;
                            g[i][j] = g[j][i] = 2;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= node; i++)
            for (int j = 1; j <= node; j++)
                if (g[i][j] == 1)
                    ans++;

        printf("%d\n", ans / 2);
    }

    return 0;
}
