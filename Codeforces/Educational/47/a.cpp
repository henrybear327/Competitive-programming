#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int games[n];
    int bills[m];
    for (int i = 0; i < n; i++)
        scanf("%d", &games[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &bills[i]);

    int pa = 0, pb = 0;
    int ans = 0;
    while (pa < n && pb < m) {
        if (games[pa] <= bills[pb]) {
            pa++;
            pb++;
            ans++;
        } else
            pa++;
    }

    printf("%d\n", ans);

    return 0;
}
