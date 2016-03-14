#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

typedef long long int ll;

int main()
{
    int n;
    scanf("%d", &n);

    ll x, y;
    scanf("%lld %lld", &x, &y);

    pair<ll, ll> inp[n];
    for (int i = 0; i < n; i++) {
        ll k, b;
        scanf("%lld %lld", &k, &b);
        inp[i].first = k * x + b;
        inp[i].second = k * y + b;
    }

    sort(inp, inp + n);

    bool ok = false;
    for (int i = 1; i < n; i++) {
        if (inp[i].second < inp[i - 1].second) {
            ok = true;
            break;
        }
    }

    printf("%s\n", ok ? "YES" : "NO");

    return 0;
}
