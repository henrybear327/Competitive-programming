#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, _d;
    scanf("%d %d", &n, &_d);

    ll d = 1LL * _d * _d;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        scanf("%lld %lld", &x, &y);

        if (x * x + y * y <= d)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
