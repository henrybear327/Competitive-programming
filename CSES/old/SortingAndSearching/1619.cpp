#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    ii inp[n * 2];
    for (int i = 0; i < n; i++) {
        int s, t;
        scanf("%d %d", &s, &t);

        inp[i * 2] = {s, 1};
        inp[i * 2 + 1] = {t, -1};
    }
    sort(inp, inp + 2 * n);

    int ans = 0, acc = 0;
    for (int i = 0; i < 2 * n; i++) {
        acc += inp[i].second;
        ans = max(ans, acc);
    }

    printf("%d\n", ans);

    return 0;
}
