// Good one
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll gcd(ll a, ll b)
{
    return a == 0 ? b : gcd(b % a, a);
}

#define EPS 1e-9
ll dist(ii a)
{
    return (a.first * a.first + a.second * a.second);
}

int main()
{
    ll ax, ay, bx, by, cx, cy;
    scanf("%lld %lld %lld %lld %lld %lld", &ax, &ay, &bx, &by, &cx, &cy);

    ii ab = ii(bx - ax, by - ay);
    ii bc = ii(cx - bx, cy - by);
    ii ac = ii(cx - ax, cy - ay);

    if (dist(ab) != dist(bc)) {
        printf("No\n");
    } else {
        ll u1 = ab.first;
        ll u2 = ab.second;
        ll v1 = ac.first;
        ll v2 = ac.second;
        bool ok = ((u1 * v2 - u2 * v1) != 0);

        printf("%s\n", ok ? "Yes" : "No");
    }

    return 0;
}
