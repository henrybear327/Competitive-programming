#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    char inp[n + 2];
    scanf("%s", inp);

    bool ok = true;
    bool open = false;
    for (int i = 0; i < n; i++) {
        char c = inp[i];
        if (open) {
            if (c == 'H')
                ok = false;
            else if (c == 'T')
                open = false;
        } else {
            if (c == 'T')
                ok = false;
            else if (c == 'H')
                open = true;
        }
    }

    if (open == true)
        ok = false;
    printf("%s\n", ok ? "Valid" : "Invalid");
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
