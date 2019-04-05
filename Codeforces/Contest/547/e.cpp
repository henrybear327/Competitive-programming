#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ll h, n;
ll ans;
bool check(ll mid, ll sum, ll prefix[])
{
    ll total = mid * sum;
    for (int i = 0; i < n; i++)
        if (h + total + prefix[i] <= 0) {
            ans = mid * n + i + 1;
            return true;
        }
    return false;
}

int main()
{
    scanf("%lld %lld", &h, &n);

    ll sum = 0;
    ll prefix[n];
    for (int i = 0; i < n; i++) {
        ll num;
        scanf("%lld", &num);

        sum += num;
        prefix[i] = sum;

        if (h + sum <= 0) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    if (sum >= 0) {
        printf("-1\n");
        return 0;
    }

    ll l = 0, r = h / -sum + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        // printf("%lld %lld %lld\n", l, mid, r);
        if (check(mid, sum, prefix))
            r = mid;
        else
            l = mid;
    }

    check(r, sum, prefix);
    printf("%lld\n", r == h + 1 ? -1 : ans);

    return 0;
}
