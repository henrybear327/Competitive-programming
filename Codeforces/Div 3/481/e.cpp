#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int mn = 0, mx = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        sum += num;
        mn = min(mn, sum);
        mx = max(mx, sum);
    }

    // printf("%d %d %d\n", mn, mx, sum);
    int ans = (m - mx + 1) - (0 - mn);
    printf("%d\n", ans < 0 ? 0 : ans);

    return 0;
}
