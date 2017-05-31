#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int res = 0;
    for (int i = 1; i <= k; i++)
        res = max(res, n % i);
    printf("%d\n", res);
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
