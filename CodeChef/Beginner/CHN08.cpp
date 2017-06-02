#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll mod = 1e9 + 7;

void solve()
{
    ll a, b, n;
    scanf("%lld %lld %lld", &a, &b, &n);

    ll data[6];
    data[0] = (a + mod) % mod;
    data[1] = (b + mod) % mod;
    data[2] = (b - a + mod) % mod;
    data[3] = (-a + mod) % mod;
    data[4] = (-b + mod) % mod;
    data[5] = (-b + a + mod) % mod;

    printf("%lld\n", (data[(n - 1) % 6] + mod) % mod);
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
