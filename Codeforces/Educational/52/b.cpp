#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

// come on long long int

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll mn, mx;

    mn = max(0LL, n - m * 2);

    mx = n;
    if (m > 0)
        for (int i = 1; i <= n; i++) {
            ll willUse = i - 1;
            if (m - willUse >= 0) {
                mx--;
                m -= willUse;
            } else {
                if (m > 0)
                    mx--;
                break;
            }
        }

    printf("%lld %lld\n", mn, mx);

    return 0;
}
