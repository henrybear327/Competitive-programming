#include <bits/stdc++.h>

// you can't use x^y%p where x%p and y%(p-1) since y is factorial and y is not
// guaranteed to < p, thus you might have some value%(p-1) causing the factorial
// to be 0 and thus answer will almost always be = 1

using namespace std;

typedef long long ll;

ll fast_pow(ll x, ll y, ll p)
{
    ll ans = (x == 0 ? 0 : 1); // 0^1 = 0

    while (y > 0) {
        if (y & 1) {
            ans = ans * x % p;
        }
        y >>= 1;
        x = x * x % p;
    }

    return ans;
}

ll solve()
{
    int x, y, p;
    scanf("%d %d %d", &x, &y, &p);

    ll ans = x % p;
    for (int i = 2; i <= y; i++) {
        ans = ans * fast_pow(ans, i, p) % p;
    }

    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %lld\n", i, solve());
    }
}
