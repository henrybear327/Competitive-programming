#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int ncase = 1;
    while (scanf("%d %d", &n, &m) == 2 && (n != 0 && m != 0)) {
        printf("Case %d: ", ncase++);

        int b[n], mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            mn = min(mn, b[i]);
        }

        for (int i = 0; i < m; i++) {
            int cur;
            scanf("%d", &cur);
        }

        if (n <= m) {
            printf("%d\n", 0);
        } else {
            printf("%d %d\n", n - m, mn);
        }
    }

    return 0;
}