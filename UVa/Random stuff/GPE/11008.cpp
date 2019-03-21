#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int gcd(int x, int y)
{
    // abs oops
    x = abs(x);
    y = abs(y);
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

bool sameLine(ii a, ii b, ii c)
{
    int dy = b.second - a.second;
    int dx = b.first - a.first;
    int g = gcd(dy, dx);
    dy /= g;
    dx /= g;
    int dyy = c.second - a.second;
    int dxx = c.first - a.first;
    g = gcd(dxx, dyy);
    dyy /= g;
    dxx /= g;

    // sign oops
    if (dx < 0)
        dx = -dx, dy = -dy;
    if (dxx < 0)
        dxx = -dxx, dyy = -dyy;

    // same line, slope = 0
    if (dx == 0 && dxx == 0)
        return true;
    if (dy == 0 && dyy == 0)
        return true;

    if (dx == dxx && dy == dyy)
        return true;
    return false;
}

int solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    ii inp[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &inp[i].first, &inp[i].second);

    int dp[1 << n];
    int oo = 0x3f3f3f3f;
    fill(dp, dp + (1 << n), oo);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        dp[1 << i] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // enumerate 2 points -> forms a line
            int line = 0;
            line |= (1 << i);
            line |= (1 << j);
            dp[line] = 1;

            // try to figure out what points are on this line
            for (int k = 0; k < n; k++) {
                if (i == k || j == k)
                    continue;
                if (!sameLine(inp[i], inp[j], inp[k]))
                    continue;

                line |= (1 << k);
                dp[line] = 1;
            }

            // if the point set S contains the entire line point set
            // we add 1 to S, meaning that 1 line is required to cover it
            for (int k = 0; k < (1 << n); k++) {
                if ((k & line) == line) {
                    // this is WOW!
                    // to update state [k], we +1 from [k without line], to avoid
                    // overlapping point
                    dp[k] = min(dp[k], 1 + dp[~line & k]);
                }
            }
        }
    }

    int ans = oo;
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) >= m)
            ans = min(ans, dp[i]);
    }
    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 0; i < ncase; i++) {
        if (i != 0)
            printf("\n");
        printf("Case #%d:\n%d\n", i + 1, solve());
    }

    return 0;
}
