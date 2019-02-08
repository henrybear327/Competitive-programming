#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);

        ll ans = 1LL * k / 2 * (a - b);
        if (k % 2 == 1)
            ans += a;

        printf("%lld\n", ans);
    }

    return 0;
}
