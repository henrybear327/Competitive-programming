#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++) {
        ll num;
        scanf("%lld", &num);

        inp[i] = __builtin_popcountll(num);
    }

    // count even interval
    int pre[n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + inp[i - 1];

    // for (int i = 0; i <= n; i++)
    // printf("%d %d\n", i, pre[i]);

    int odd = 0, even = 0;
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        // update
        if (pre[i - 2] % 2 == 0)
            even++;
        else
            odd++;

        // get count
        if (pre[i] % 2 == 0)
            ans += even;
        else
            ans += odd;
    }
    // printf("ans = %lld\n", ans);

    // filter out invalid interval
    // 3
    // 1 15 1
    for (int i = 0; i < n; i++) {
        int tmp = inp[i];
        int mx = tmp;
        for (int j = 1; j < 61 && i + j < n; j++) { // [i, i + j]
            tmp += inp[i + j];
            mx = max(mx, inp[i + j]);

            // printf("%d %d %d %d %lld\n", i, j, tmp, mx, ans);
            if (tmp % 2 == 0 && mx > tmp - mx)
                ans--;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
