#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    int one = 0, nOne = 0, other = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num == 1)
            one++;
        else if (num == 0)
            zero++;
        else if (num == -1)
            nOne++;
        else
            other++;
    }

    bool ok = true;
    if (other > 1)
        ok = false;
    else if (other == 1 && nOne > 0)
        ok = false;
    else if (nOne > 1 && one == 0)
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
