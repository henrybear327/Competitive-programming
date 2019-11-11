#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    ll n;
    scanf("%lld", &n);

    ll ans = 1 + n;
    for (ll i = 1; i * i <= n; i++) {
        ll a = i;
        ll b = n / i;
        if (a * b == n) {
            ans = min(ans, a + b - 2);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
