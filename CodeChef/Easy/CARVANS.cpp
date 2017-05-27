#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);

    int cnt = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (mn >= tmp) {
            cnt++;
            mn = tmp;
        }
    }

    printf("%d\n", cnt);
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
