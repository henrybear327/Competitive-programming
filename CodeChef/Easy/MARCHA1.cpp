#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inp[i]);

    bool can[m + 1];
    memset(can, false, sizeof(can));
    can[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = m - inp[i]; j >= 0; j--) {
            if (can[j])
                can[j + inp[i]] = true;
        }
        if (inp[i] <= m) // caused RE
            can[inp[i]] = true;
    }

    printf("%s\n", can[m] ? "Yes" : "No");

    /*
    // enumeration
    for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        if ((i >> j) & 1)
            sum += inp[j];
    }
    if (sum == m) {
        printf("Yes\n");
        return;
    }
    }
    printf("No\n");
    */
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
