#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    ii inp[q];
    int coverage[n + 1] = {0};
    int ans = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &inp[i].first, &inp[i].second);
        for (int j = inp[i].first; j <= inp[i].second; j++)
            coverage[j]++;
    }
    sort(inp, inp + q);

    for (int i = 1; i <= n; i++)
        ans += coverage[i] > 0;

    int one[n + 1] = {0}, two[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        one[i] = coverage[i] == 1;
        two[i] = coverage[i] == 2;
    }

    int pre1[n + 1] = {0};
    int pre2[n + 1] = {0};
    for (int i = 1; i <= n; i++)
        pre1[i] = pre1[i - 1] + one[i];
    for (int i = 1; i <= n; i++)
        pre2[i] = pre2[i - 1] + (one[i] || two[i]);

    int mx = 0;
    for (int i = 0; i < q; i++)
        for (int j = i + 1; j < q; j++) {
            int l1 = inp[i].first;
            int r1 = inp[i].second;
            int l2 = inp[j].first;
            int r2 = inp[j].second;

            if (l1 <= l2 && l2 <= r1) {
                int overlapL = l2;
                int overlapR = min(r1, r2);

                int cnt = 0;
                if (overlapL - 1 >= l1)
                    cnt += pre1[overlapL - 1] - pre1[l1 - 1];
                cnt += pre2[overlapR] - pre2[overlapL - 1];
                if (overlapR + 1 <= max(r1, r2))
                    cnt += pre1[max(r1, r2)] - pre1[overlapR];

                mx = max(mx, ans - cnt);
            } else {
                int cnt = ans - (pre1[r2] - pre1[l2 - 1]) - (pre1[r1] - pre1[l1 - 1]);
                mx = max(mx, cnt);
            }
        }

    printf("%d\n", mx);

    return 0;
}
