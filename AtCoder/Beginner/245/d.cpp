#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    ll a[n + 1];
    for (int i = 0; i <= n; i++)
        scanf("%lld", &a[i]);

    ll b[m + 1];

    ll c[n + m + 1];
    for (int i = 0; i <= n + m; i++)
        scanf("%lld", &c[i]);

    // init
    b[m] = c[n + m] / a[n];

    // cal
    int b_stop = m - 1;
    for (int i = n + m - 1; i >= 0 && b_stop >= 0; i--) { // c
        ll tot = 0;
        for (int x = i, y = 0; x >= 0 && y <= m; x--, y++) {
            if (x <= n && y <= m) {
                if (y == b_stop)
                    continue;

                tot += a[x] * b[y];
            }
        }

        b[b_stop] = (c[i] - tot) / a[n];

        b_stop--;
    }

    // ans
    for (int i = 0; i <= m; i++)
        printf("%lld%c", b[i], i == m ? '\n' : ' ');

    return 0;
}
