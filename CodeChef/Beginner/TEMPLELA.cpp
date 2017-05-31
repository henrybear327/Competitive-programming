#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    int inp[n], rev[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        rev[i] = inp[i];
    }
    reverse(rev, rev + n);

    bool ok = true;
    if (n % 2 == 0)
        ok = false;

    if (inp[0] != 1 || inp[n - 1] != 1)
        ok = false;

    for (int i = 1; i < n / 2; i++)
        if (inp[i] - inp[i - 1] != 1)
            ok = false;
    for (int i = n / 2 + 1; i < n; i++)
        if (inp[i] - inp[i - 1] != -1)
            ok = false;

    printf("%s\n", ok ? "yes" : "no");
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
