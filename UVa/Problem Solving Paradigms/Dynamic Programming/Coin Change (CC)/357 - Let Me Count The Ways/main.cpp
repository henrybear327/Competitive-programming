#include <bits/stdc++.h>

using namespace std;

const int c[5] = {1, 5, 10, 25, 50};

typedef long long ll;

ll dp[33333];
void build()
{
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    // 往後丟 : 全部排列
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         if (i + c[j] <= n) {
    //             dp[i + c[j]] += dp[i];
    //         }
    //     }
    // }

    // 其實一個硬幣只try一次->交換迴圈順序即可
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i <= 33333; i++) {
            if (i - c[j] >= 0) {
                dp[i] += dp[i - c[j]];
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    //     printf("%d%c", dp[i], i == n ? '\n' : ' ');
}

void solve(int n)
{
    if (dp[n] == 1)
        printf("There is only 1 way to produce %d cents change.\n", n);
    else
        printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
}

int main()
{
    int n;
    build();
    while (scanf("%d", &n) == 1) {
        solve(n);
    }

    return 0;
}