#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        int s, a, b, c;
        scanf("%d %d %d %d", &s, &a, &b, &c);
        ll ans = 0;
        ll mx = s / c;
        ans += mx / a * b;
        ans += mx;

        printf("%lld\n", ans);
    }

    return 0;
}
