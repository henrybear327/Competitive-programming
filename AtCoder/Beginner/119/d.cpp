#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);

    ll s[a], t[b];
    for (int i = 0; i < a; i++)
        scanf("%lld", &s[i]);
    for (int i = 0; i < b; i++)
        scanf("%lld", &t[i]);
    sort(s, s + a);
    sort(t, t + b);

    for (int i = 0; i < q; i++) {
        ll num;
        scanf("%lld", &num);
        // printf("%lld\n", num);

        int r1 = lower_bound(s, s + a, num) - s;
        int l1 = r1 > 0 ? r1 - 1 : r1;
        if (r1 == a)
            r1--;
        int r2 = lower_bound(t, t + b, num) - t;
        int l2 = r2 > 0 ? r2 - 1 : r2;
        if (r2 == b)
            r2--;

        ll ans = LLONG_MAX;

        // printf("%d %d %d %d\n", l1, r1, l2, r2);
        if (s[r1] > num && t[r2] > num)
            ans = min(ans, max(s[r1], t[r2]) - num);
        if (s[l1] < num && t[l2] < num)
            ans = min(ans, num - min(s[l1], t[l2]));
        if (num > s[l1] && t[r2] > s[l1]) // LR
            ans = min(ans, num - s[l1] + t[r2] - s[l1]);
        if (s[r1] > num && s[r1] > t[l2]) // RL
            ans = min(ans, s[r1] - num + s[r1] - t[l2]);
        if (num > t[l2] && s[r1] > t[l2]) // LR
            ans = min(ans, num - t[l2] + s[r1] - t[l2]);
        if (t[r2] > num && t[r2] > s[l1]) // RL
            ans = min(ans, t[r2] - num + t[r2] - s[l1]);

        printf("%lld\n", ans);
    }

    return 0;
}
