#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; i++) {
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp]++;
    }

    for (int i = 0; i < k; i++) {
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp]++;
    }

    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 2)
            a++;
        else if (cnt[i] == 0)
            b++;
    }

    printf("%d %d\n", a, b);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
