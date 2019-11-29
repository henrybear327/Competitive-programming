#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll gcd(ll a, ll b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int main()
{
    ll a, b;
    scanf("%lld %lld", &a, &b);

    ll g = gcd(a, b);

    int ans = 1;
    for (ll i = 2; i * i <= g; i++) {
        int cnt = 0;
        while (g % i == 0) {
            g /= i;
            cnt++;
        }

        if (cnt > 0)
            ans++;
    }

    if (g > 1)
        ans++;

    printf("%d\n", ans);

    return 0;
}
