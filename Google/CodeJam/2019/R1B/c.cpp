#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 100010;
const int MAX_LOG_N = 18;
struct Sptb {
    int sp[MAX_LOG_N][MAX_N]; // MAX_LOG_N = ceil(lg(MAX_N))

    void build(int inp[], int n)
    {
        for (int j = 0; j < n; j++)
            sp[0][j] = inp[j];

        for (int i = 1; (1 << i) <= n; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
    }

    int query(int l, int r) // [l, r)
    {
        int k = floor(log2(r - l));
        return max(sp[k][l], sp[k][r - (1 << k)]);
    }
} sa, sb;

void solve()
{
    int n, diff;
    scanf("%d %d", &n, &diff);

    int a[n], b[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    sa.build(a, n);
    sb.build(b, n);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (abs(a[i] - b[i]) <= diff) {
            // binary search
            int cntl, cntr;
            {
                ll l = i, r = n + 1;
                while (r - l > 1) {
                    ll mid = (l + r) / 2;
                    int tmp = abs(sa.query(i, mid + 1) - sb.query(i, mid + 1));
                    if (tmp <= diff)
                        l = mid;
                    else
                        r = mid;
                }

                cntl = r - l;
                // ans += cntl;
            }

            {
                ll l = -1, r = i;
                while (r - l > 1) {
                    ll mid = (l + r) / 2;
                    int tmp = abs(sa.query(mid, i + 1) - sb.query(mid, i + 1));
                    // printf("mid %lld %d\n", mid, tmp);
                    if (tmp <= diff)
                        r = mid;
                    else
                        l = mid;
                    // printf("l %lld %lld\n", l, r);
                }

                // printf("%d %lld %lld\n", i, l, r);
                cntr = i - l;
                // ans += cntr;
            }

            if (cntl != 1 && cntr != 1) {
                ll tot = cntl + cntr - 1;
                ans += tot * (tot - 1) / 2;
            } else {
                ans += max(cntl, cntr);
            }
        }
    }

    printf("%lld\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
