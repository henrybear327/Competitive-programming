#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);

    ll g = gcd(n, k);
    ll l = (ll)n * k / g;

    printf("%lld %lld\n", g, l);
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
