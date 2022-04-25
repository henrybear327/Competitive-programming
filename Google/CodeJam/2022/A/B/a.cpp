#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }

    int l = 0, r = n - 1;
    int ans = 0;
    int mx = 0;
    while (l <= r) {
        if (inp[l] <= inp[r]) {
            if (inp[l] >= mx) {
                mx = max(inp[l], mx);
                ans++;
            }
            l++;
        } else {
            if (inp[r] >= mx) {
                mx = max(inp[r], mx);
                ans++;
            }
            r--;
        }
    }

    printf("%d\n", ans);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
