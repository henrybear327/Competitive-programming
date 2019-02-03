#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll mod = 1e9 + 7;

int main()
{
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);

    int rem[3] = {0};
    // for (int i = l; i <= r; i++)
    //  rem[i % 3]++;
    int cnt = r - l + 1;
    rem[0] = rem[1] = rem[2] = cnt / 3;
    l += cnt / 3 * 3;
    for (int i = l; i <= r; i++)
        rem[i % 3]++;

    ll dp[3][n];
    dp[0][0] = rem[0];
    dp[1][0] = rem[1];
    dp[2][0] = rem[2];
    for (int i = 1; i < n; i++) {
        dp[0][i] = (dp[0][i - 1] * rem[0] + dp[1][i - 1] * rem[2] +
                    dp[2][i - 1] * rem[1]) %
                   mod; // 0+0, 1+2, 2+1
        dp[1][i] = (dp[0][i - 1] * rem[1] + dp[1][i - 1] * rem[0] +
                    dp[2][i - 1] * rem[2]) %
                   mod; // 1+0, 0+1, 2+2
        dp[2][i] = (dp[2][i - 1] * rem[0] + dp[1][i - 1] * rem[1] +
                    dp[0][i - 1] * rem[2]) %
                   mod; // 0+2, 1+1, 2+0
    }

    printf("%lld\n", dp[0][n - 1]);

    return 0;
}
