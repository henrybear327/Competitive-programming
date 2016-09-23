#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 0; i < ncase; i++) {
        int n;
        scanf("%d", &n);

        int inp[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &inp[j]);
        }

        int ans = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k)
                    continue;

                int num = inp[j] ^ inp[k];
                int p1 = __builtin_popcount(num);

                ans = max(ans, abs(p1));
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
