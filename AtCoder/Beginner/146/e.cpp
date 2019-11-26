#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    ll pre[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        ll num;
        scanf("%lld", &num);
        pre[i] = pre[i - 1] + num;
    }

    // for (int i = 0; i <= n; i++)
    //  printf("%d %d\n", i, pre[i]);

    map<ll, int> cnt;
    ll ans = 0;
    for (int j = 0; j <= n; j++) {
        if (j - k >= 0)
            cnt[(pre[j - k] - (j - k) + k) % k]--;

        ans += cnt[(pre[j] - j + k) % k];

        cnt[(pre[j] - j + k) % k]++;

        // printf("%d %lld\n", j, ans);
    }

    printf("%lld\n", ans);

    return 0;
}
