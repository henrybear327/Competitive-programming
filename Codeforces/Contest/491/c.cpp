#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool check(ll n, ll k)
{
    ll a = 0, b = 0;
    while (n > 0) {
        a += min(k, n);
        n -= min(k, n);
        if (n > 0) {
            b += n / 10;
            n -= n / 10;
        }
    }

    return a >= b;
}

int main()
{
    ll n;
    scanf("%lld", &n);

    ll l = 0, r = n + 1;
    // xxxoooo
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(n, mid))
            r = mid;
        else
            l = mid;
    }

    // r
    printf("%lld\n", r);

    return 0;
}
