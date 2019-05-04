#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, diff;
    scanf("%d %d", &n, &diff);

    int a[n], b[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int mxa = 0, mxb = 0;
            for (int k = i; k <= j; k++) {
                mxa = max(mxa, a[k]);
                mxb = max(mxb, b[k]);
            }

            if (abs(mxa - mxb) <= diff)
                ans++;
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
}
