#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    ll h, n;
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

    ll mn = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ll remaining = h + prefix[i];
        if (remaining > 0) {
            ll ans = i + 1 + ((remaining + (-sum - 1)) / -sum * n);
            mn = min(mn, ans);
            // printf("%d %d\n", i, ans);
        }
    }

    printf("%lld\n", mn == INT_MAX ? -1 : mn);

    return 0;
}
