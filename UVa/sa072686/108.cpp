#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve(int n)
{
    int inp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &inp[i][j]);

    // build prefix sum table by column
    int pre[n + 1][n];
    memset(pre, 0, sizeof(pre));
    for (int c = 0; c < n; c++) {
        for (int r = 1; r <= n; r++) {
            pre[r][c] = pre[r - 1][c] + inp[r - 1][c];
        }
    }

    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j < n; j++)
    //         printf("%3d%c", pre[i][j], j == n - 1 ? '\n' : ' ');

    // enumerate upper row, enumerate lower row, enumerate column
    int mx = -0x3f3f3f3f;
    for (int r1 = 0; r1 < n; r1++) {
        for (int r2 = r1 + 1; r2 <= n; r2++) { // [r1, r2)
            int best = -0x3f3f3f3f;
            for (int c = 0; c < n; c++) {
                // printf("%d %d\n", best, mx);
                int sum = pre[r2][c] - pre[r1][c];
                best = max(sum, best + sum);
                mx = max(mx, best);
                // printf("%d %d %d %d %d %d\n", r1, r2, c, sum, best, mx);
            }
        }
    }

    printf("%d\n", mx);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
        solve(n);

    return 0;
}
