#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);

    if (n > 2 * k) {
        n = n - k * ((n - 2 * k) / k);
    }

    set<ll> seen;
    ll mn = LLONG_MAX;
    while (true) {
        if (seen.count(n) == 1) {
            printf("%lld\n", mn);
            break;
        }

        seen.insert(n);
        mn = min(mn, n);
        n = abs(n - k);
    }

    return 0;
}
