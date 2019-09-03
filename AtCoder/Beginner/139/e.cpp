#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int constraint[n][n - 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            scanf("%d", &constraint[i][j]), constraint[i][j]--;

    int pos[n] = {0};
    int g[2][n];
    memset(g, -1, sizeof(g));
    for (int i = 0; i < n; i++) {
        g[0][i] = constraint[i][pos[i]];
    }

    /*
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++)
                printf("%d%c", g[i][j], j == n - 1 ? '\n' : ' ');
        }
        printf("\n");
    */
    int ans = 0;
    while (true) {
        bool has = false;
        int cur = ans & 1;
        int nxt = cur ^ 1;
        // printf("cur %d nxt %d\n", cur, nxt);
        for (int i = 0; i < n; i++) {
            int &target = g[cur][i];
            if (g[cur][i] >= 0 && i == g[cur][target]) {
                has = true;
                g[nxt][i] = pos[i] + 1 < n - 1 ? constraint[i][pos[i] + 1] : -1;
                pos[i]++;
            } else {
                g[nxt][i] = g[cur][i];
            }
        }

        if (has == false)
            break;

        /*
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++)
                printf("%d%c", g[i][j], j == n - 1 ? '\n' : ' ');
        }
        printf("\n");
        getchar();
        */

        ans++;
    }

    for (int i = 0; i < n; i++)
        if (pos[i] < n - 1)
            ans = 0;

    printf("%d\n", ans == 0 ? -1 : ans);

    return 0;
}
