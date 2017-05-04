#include <cstdio>

typedef long long ll;
int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        ll m;
        scanf("%lld", &m);

        ll b = m;
        ll ans = 0;
        while (b > 0) {
            ll q = m / b;
            ll b1 = m / (q + 1);
            ans += q * (b - b1);
            b = b1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
