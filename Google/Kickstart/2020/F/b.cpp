#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n, k;
    scanf("%d %d", &n, &k);

    pair<int, int> inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &inp[i].first, &inp[i].second);
    sort(inp, inp + n);

    int ans = 0;
    int left = -k;
    for (int i = 0; i < n; i++) {
        int s = inp[i].first, t = inp[i].second;

        if (t <= left + k) {
            // skip since covered
        } else {
            if (left + k >= s)
                s = left + k;

            int len = t - s;
            int need = (len + k - 1) / k;
            ans += need;
            // printf("%d %d\n", i, need);
            left = s + (need - 1) * k;
        }
    }

    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++)
        printf("Case #%d: %d\n", i, solve());

    return 0;
}
