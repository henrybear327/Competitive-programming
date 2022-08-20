#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int x = (n + 2 * k) / (2 * k + 1); // ceil
    int ans[x];
    int pos = 0;
    for (int i = 0; i < x; i++) {
        ans[i] = pos;
        pos += 2 * k + 1;
    }

    if (ans[x - 1] + k <= n - 1) {
        int diff = n - 1 - (ans[x - 1] + k);
        for (int i = 0; i < x; i++)
            ans[i] += diff;
    }

    printf("%d\n", x);
    for (int i = 0; i < x; i++)
        printf("%d%c", ans[i] + 1, i == x - 1 ? '\n' : ' ');

    return 0;
}
