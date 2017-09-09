#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 222;
const int MAX = 0x3f3f3f3f;
int g[N][N];

int main()
{
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            g[i][j] = i == j ? 0 : MAX;

    int seq[r];
    for (int i = 0; i < r; i++) {
        scanf("%d", &seq[i]);
        seq[i]--;
    }
    sort(seq, seq + r);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        u--;
        v--;
        g[u][v] = g[v][u] = w;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int ans = MAX;
    do {
        int sum = 0;
        for (int i = 1; i < r; i++)
            sum += g[seq[i - 1]][seq[i]];
        ans = min(ans, sum);
    } while (next_permutation(seq, seq + r));

    printf("%d\n", ans);

    return 0;
}
