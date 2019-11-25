#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    // a * n + b * d(n)
    ll a, b, x;
    scanf("%lld %lld %lld", &a, &b, &x);

    ll ans = 0;
    ll lb = 1, ub = 10;
    for (int i = 1; i <= 10; i++) {
        ll rem = x - b * i;
        ll target = rem / a;
        if (rem >= 0 && lb <= target) {
            ans = max(ans, min(target, min(ub - 1, 1000000000LL)));
        }
        lb *= 10;
        ub *= 10;
    }

    printf("%lld\n", ans);

    return 0;
}
