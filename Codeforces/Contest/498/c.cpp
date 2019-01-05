#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &inp[i]);

    ll pre[n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + inp[i];

    unordered_map<ll, int> suf;
    ll sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += inp[i];
        int cur = suf[sum];
        if (cur == 0)
            cur = i;
        suf[sum] = cur;
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (suf.find(pre[i]) != suf.end()) {
            int pos = suf[pre[i]];
            if (i < pos) {
                ans = pre[i];
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
