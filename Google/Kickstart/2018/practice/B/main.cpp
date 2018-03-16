#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// mid is always 0
// A 0 B
// A mid is always 0, B mid is always 1
// recurse...

int ans(ll n, int lenp, bool goLeft)
{
    ll len = (1LL << lenp) - 1;

    // printf("from %s, %lld %lld\n", goLeft ? "left" : "right", n, len);
    ll mid = len / 2;
    if (n == mid || len == 1) {
        if (goLeft)
            return 0;
        return 1;
    }

    goLeft = true;
    if (n > mid) {
        n -= mid + 1;
        goLeft = false;
    }
    return ans(n, lenp - 1, goLeft);
}

int solve()
{
    ll n;
    scanf("%lld", &n);
    n--;

    if (n % 2 == 0) {
        if (n % 4 == 0)
            return 0;
        return 1;
    }

    // printf("%d\n", ans(n, 62, true)); // 2^62 - 1
    return ans(n, 62, true); // 2^62 - 1
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
}
