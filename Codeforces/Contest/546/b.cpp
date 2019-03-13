#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    /*
    to minimize moves = walk the short path first
    to minimize throws = first one, put it at adjacent one; 2+, throw to the first
    one
    */

    int n, m;
    scanf("%d %d", &n, &m);

    int ans = 0;
    ans += n; // pick
    // throw
    if (n == 1)
        ans += 1;

    if (n >= 2)
        ans += 3;
    if (n > 2)
        ans += n - 2;

    // move
    int l = m - 1;
    int r = n - m;

    ans += min(l, r) * 2 + max(l, r);

    printf("%d\n", ans);

    return 0;
}
