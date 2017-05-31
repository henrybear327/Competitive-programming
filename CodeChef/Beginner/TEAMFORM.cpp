#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    bool used[n];
    memset(used, 0, sizeof(used));

    bool ok = true;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;

        if (used[u] == false)
            used[u] = true;
        else
            ok = false;

        if (used[v] == false)
            used[v] = true;
        else
            ok = false;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (used[i] == false)
            cnt++;

    printf("%s\n", ok && cnt % 2 == 0 ? "yes" : "no");
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
