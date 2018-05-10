#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int getRem(int x, int k)
{
    if (x >= 0)
        return x % k;
    return (x + 20000 * k) % k; // GG
}

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);

    bool dp[k][n + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);

        for (int j = 0; j < k; j++) {
            if (dp[j][i - 1] == true) {
                dp[getRem(j + num, k)][i] = true;
                dp[getRem(j - num, k)][i] = true;
            }
        }
    }

    // for (int i = 0; i < k; i++) {
    //     for (int j = 0; j <= n; j++)
    //         printf("%d ", dp[i][j]);
    //     puts("");
    // }

    if (dp[0][n])
        printf("Divisible\n");
    else
        printf("Not divisible\n");
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
