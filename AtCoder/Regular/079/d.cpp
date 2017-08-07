#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll k;
    scanf("%lld", &k);

    ll n = min(50LL, k);
    n = n < 2 ? 2 : n;

    ll q = k / n;
    ll r = k % n;

    ll ans[n];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) {
        ans[i] = q + i;
    }
    reverse(ans, ans + n);

    for (int i = 0; i < r; i++)
        ans[i]++;

    printf("%lld\n", n);
    for (int i = 0; i < n; i++)
        printf("%lld%c", ans[i], i == n - 1 ? '\n' : ' ');

    return 0;
}