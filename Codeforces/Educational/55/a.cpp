#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n, x, y, d;
    scanf("%d %d %d %d", &n, &x, &y, &d);

    // 1...n

    int ans = INT_MAX;
    if (x == y)
        ans = 0;
    else if (x < y && (y - x) % d == 0)
        ans = min(ans, (y - x) / d);
    else if (x > y && (x - y) % d == 0)
        ans = min(ans, (x - y) / d);

    if ((y - 1) % d == 0)
        ans = min(ans, (x + d - 2) / d + (y - 1) / d);
    if ((n - y) % d == 0)
        ans = min(ans, (n - x + d - 1) / d + (n - y) / d);

    printf("%d\n", ans == INT_MAX ? -1 : ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();

    return 0;
}
