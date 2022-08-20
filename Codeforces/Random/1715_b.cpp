#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, k, b, s;
    scanf("%lld %lld %lld %lld", &n, &k, &b, &s);
    ll ans[n];

    if (s < k * b) {
        printf("-1\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        ll tmp;
        if (i == 0) {
            tmp = min(k * b + k - 1, s);
        } else {
            tmp = min(k - 1, s);
        }
        s -= tmp;
        ans[i] = tmp;
    }

    if (s > 0) {
        printf("-1\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%lld%c", ans[i], i == n - 1 ? '\n' : ' ');
        }
    }
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
