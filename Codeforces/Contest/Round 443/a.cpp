#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll s, t;
        scanf("%lld %lld", &s, &t);
        ans++;

        if (s >= ans)
            ans = s;
        else {
            ans = (ans - s + t - 1) / (t)*t + s;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
