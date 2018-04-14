#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

struct Cashier {
    ll m, s, p;
};

ll r, b, c;
Cashier cashier[1111];
bool check(ll mid)
{
    // solve x
    ii sol[c]; // solution, who
    for (int i = 0; i < c; i++) {
        // s * x + p <= mid
        // x <= (mid - p) / s
        ll x = (mid - cashier[i].p) / cashier[i].s;
        // printf("m %lld s %lld p %lld\n", cashier[i].m, cashier[i].s,
        // cashier[i].p);
        if (x < 0)
            x = 0;
        sol[i] = ii(min(x, cashier[i].m), i);
        // printf("check mid %lld: %d %lld\n", mid, i, x);
    }
    sort(sol, sol + c);

    // check first B
    ll acc = 0;
    // for(int i = 0; i < c; i++)
    // printf("%d %d\n", i, sol[i].first);
    for (int i = 0; i < r; i++) {
        acc += sol[c - 1 - i].first;
    }
    /// printf("mid %lld acc %lld\n", mid, acc);
    return acc >= b;
}

ll solve()
{
    scanf("%lld %lld %lld", &r, &b, &c);

    ll left = 0, right = 1e18 + 1e9 + 100;
    for (int i = 0; i < c; i++) {
        scanf("%lld %lld %lld", &cashier[i].m, &cashier[i].s, &cashier[i].p);
    }

    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        // printf("l %lld mid %lld r %lld\n", left, mid, right);
        // printf("check %d\n", check(mid));
        if (check(mid))
            right = mid;
        else
            left = mid;
    }

    return right;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %lld\n", i, solve());
    }
    return 0;
}
