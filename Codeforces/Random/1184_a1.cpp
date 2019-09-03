#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    // H(x, y) = x*x+2xy+x+1

    ll r;
    scanf("%lld", &r);

    if (r == 1) {
        printf("NO\n");
        return 0;
    }

    for (ll x = 1; x <= 1000000; x++) {
        ll y = (r - 1 - x - x * x) / 2 / x;
        if (r == x * x + 2 * x * y + x + 1 && y > 0) {
            printf("%lld %lld\n", x, y);
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}
