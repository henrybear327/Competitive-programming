#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int dp[2][13000];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    ii inp[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &inp[i].first, &inp[i].second);

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j - inp[i].first < 0)
                dp[i % 2][j] = dp[(i % 2) ^ 1][j];
            else
                dp[i % 2][j] = max(dp[(i % 2) ^ 1][j],
                                   dp[(i % 2) ^ 1][j - inp[i].first] + inp[i].second);
        }
    }

    printf("%d\n", dp[n % 2][m]);

    return 0;
}
