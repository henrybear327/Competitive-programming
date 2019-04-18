#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int mod = 1e9 + 7;
int main()
{
    int n;
    scanf("%d", &n);

    if (n == 3) {
        printf("61\n");
        return 0;
    }

    ll ans = 1;
    ll dp[n + 1];
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * 4 % mod;
        dp[i + 1] = ans;
    }

    for (int i = 0; i + 3 <= n; i++) {
        ll left = dp[i - 0] * 3 % mod;
        ll right = dp[n - (i + 3)] * 3 % mod;
        ans = (ans - left + mod) % mod;
        ans = (ans - right + mod) % mod;
        if (i != 0)
            ans = (ans - 1 + mod) % mod;
        if (i + 3 != n)
            ans = (ans - 1 + mod) % mod;
    }
    printf("%lld\n", ans);

    return 0;
}
