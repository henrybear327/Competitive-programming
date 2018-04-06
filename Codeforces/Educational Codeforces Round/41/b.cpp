#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int theorem[n], awake[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &theorem[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &awake[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (awake[i] == 1)
            ans += theorem[i];

    int inc = 0;
    for (int i = 0; i < m; i++)
        if (awake[i] == 0)
            inc += theorem[i];

    int mx = 0;
    mx = max(mx, inc);
    for (int i = m; i < n; i++) {
        if (awake[i] == 0)
            inc += theorem[i];
        if (awake[i - m] == 0)
            inc -= theorem[i - m];
        mx = max(mx, inc);
    }
    printf("%d\n", ans + mx);

    return 0;
}
