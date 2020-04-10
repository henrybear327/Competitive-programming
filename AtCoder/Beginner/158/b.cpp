#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    ll n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);

    ll ans = 0;
    ll gp = n / (a + b);
    ans += a * gp;

    n %= (a + b);
    if (n >= a)
        ans += a;
    else
        ans += n;

    printf("%lld\n", ans);

    return 0;
}
