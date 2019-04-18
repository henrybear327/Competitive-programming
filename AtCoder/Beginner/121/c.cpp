#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    ii inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &inp[i].first, &inp[i].second);

    sort(inp, inp + n);

    ll ans = 0;
    for (int i = 0; m > 0 && i < n; i++) {
        ans += (ll)min(m, inp[i].second) * inp[i].first;
        m -= inp[i].second;
    }

    printf("%lld\n", ans);

    return 0;
}
