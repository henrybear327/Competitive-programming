#include <algorithm>
#include <cstdio>

using namespace std;

int n, s;

void solve()
{
    scanf("%d %d", &n, &s);

    int inp[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &inp[i]);

    int pre[n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + inp[i];

    int ans = n + 1;
    int l = 0; // [l, r)
    for (int r = 1; r <= n; r++) {
        int diff = pre[r] - pre[l];
        if (diff >= s)
            ans = min(ans, r - l);

        if (l < r) {
            if (diff < s)
                continue;
            else {
                l++;
                r--;
            }
        }
    }

    if (ans == n + 1)
        ans = 0;
    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
