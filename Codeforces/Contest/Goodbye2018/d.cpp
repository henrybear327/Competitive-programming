#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 998244353;
// ll dp[2][1000010];

int main()
{
    int n;
    scanf("%d", &n);
    ll ans = 0;

    /*
    memset(dp, 0, sizeof(dp));
    dp[0][2] = 1;
    int cur = 0;
    for (int i = 3; i <= n; i++) {
        int next = (cur == 0 ? 1 : 0);
        for (int j = 2; j < i; j++) {
            dp[next][j] = dp[cur][j] * i % mod;
        }
        dp[next][i] = i - 1;

        cur = next;
    }
    // for (int i = 0; i < 10; i++)
    // printf("%d %d\n", i, dp[cur][i]);
    */

    ll dp[n + 1] = {0};
    dp[n] = n - 1;
    ll fac = n;
    ll nxt = n - 1;
    for (int i = n - 1; i >= 2; i--) {
        // printf("i %d fac %lld\n", i, fac);
        dp[i] = (i - 1) * fac % mod;
        fac = fac * nxt % mod;
        nxt--;
    }

    //for(int i = 0; i <= n; i++)
      //  printf("%d %lld\n", i, dp[i]);

    for (int i = 2; i < n; i++) {
        ll change = n - i;
        // ans = (ans + dp[cur][i] * change % mod) % mod;
        ans = (ans + dp[i] * change % mod) % mod;
    }

    fac = 1;
    for (int i = 2; i <= n; i++) {
        fac = fac * i % mod;
    }
    ans = (ans + fac) % mod;

    printf("%lld\n", ans);

    return 0;
}
