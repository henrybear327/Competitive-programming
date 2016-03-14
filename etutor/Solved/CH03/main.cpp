#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int g[110][110];

int main()
{
    int node;
    while (scanf("%d", &node) == 1 && node) {
        memset(g, 0, sizeof(g));

        for (int i = 1; i <= node; i++) {
            for (int j = i + 1; j <= node; j++) {
                int tmp;
                scanf("%d", &tmp);

                g[i][j] = g[j][i] = tmp;
            }
        }

        /*
        for (int i = 1; i <= node; i++) {
            for (int j = 1; j <= node; j++) {
                printf("%d ", g[i][j]);
            }
            printf("\n");
        }
        */

        int deg[110] = {0}, ev[110] = {0};
        for (int i = 1; i <= node; i++) {
            for (int j = 1; j <= node; j++) {
                if (g[i][j]) {
                    deg[i]++;
                }
            }
        }

        for (int i = 1; i <= node; i++) {
            for (int j = 1; j <= node; j++) {
                if (g[i][j]) {
                    for (int k = 1; k <= node; k++) {
                        if (g[j][k] && g[i][k]) {
                            ev[i]++;
                            // the edges between the vertices that is adjancent to the node i
                        }
                    }
                }
            }
            ev[i] /= 2;
        }

        /*
        for (int i = 1; i <= node; i++)
            printf("%d %d\n", deg[i], ev[i]);
        */

        double ans = -1;
        for (int i = 1; i <= node; i++) {
            double CC =
                deg[i] >= 2
                ? 2.0 * (double)ev[i] / ((double)deg[i] * ((double)deg[i] - 1.0))
                : 0.0;
            ans = max(ans, CC);
        }

        printf("%.3f\n", ans);
    }

    return 0;
}
