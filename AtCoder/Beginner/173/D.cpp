#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    ll n;
    scanf("%lld", &n);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);
    sort(inp, inp + n, greater<int>());

    ll ans = 0;
    /* WA
    int mx1 = inp[0];
    int mx2 = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans += min(mx1, mx2);
        mx1 = mx2;
        mx2 = inp[i];
    }
    */

    for (int i = 1; i < n; i++) {
        ans += inp[i / 2];
    }

    printf("%lld\n", ans);

    return 0;
}
