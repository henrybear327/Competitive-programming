#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    ll n;
    scanf("%lld", &n);

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        cnt[num]++;
    }

    int val[cnt.size() + 1], pre[cnt.size() + 1];
    val[0] = pre[0] = 0;
    int idx = 1;
    for (auto i : cnt)
        val[idx] = i.first, pre[idx] = pre[idx - 1] + i.second, idx++;

    ll ans = 1LL * n * (n - 1) * (n - 2) / 6;

    for (int i = 1; i < (int)cnt.size() + 1; i++) {
        for (int j = i; j < (int)cnt.size() + 1; j++) {
            if (i == j && cnt[val[i]] == 1) {
                continue;
            }

            int target = val[i] + val[j];
            int lb = lower_bound(val + 1, val + idx, target) - val;
            // printf("%d %d %d\n", i, j, idx);
            if (i == j)
                ans -= 1LL * cnt[val[i]] * (cnt[val[i]] - 1) / 2 *
                       (pre[idx - 1] - pre[lb - 1]);
            else
                ans -= 1LL * cnt[val[i]] * cnt[val[j]] * (pre[idx - 1] - pre[lb - 1]);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
