#include <bits/stdc++.h>

using namespace std;

// 0:06

void solve()
{
    int a[3], m[3];
    for (int i = 0; i < 3; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < 3; i++)
        scanf("%d", &m[i]);

    int x = 1;
    while (1) {
        bool ok = true;
        for (int i = 0; i < 3; i++)
            if (x % m[i] == a[i])
                continue;
            else
                ok = false;

        if (ok)
            break;
        x++;
    }
    printf("%d\n", x);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();

    return 0;
}
