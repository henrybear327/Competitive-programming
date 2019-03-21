#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
    x = abs(x);
    y = abs(y);
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

typedef pair<int, int> ii;
int solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    ii inp[20];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &inp[i].first, &inp[i].second);

    int acc = 0;
    bool fucked[20] = {false};
    int cnt = 0;
    while (acc < m) {
        int mx = 0;
        int mxFucked[20] = {0};
        for (int i = 1; i < (1 << n); i++) {
            int idx = 0;
            int cur[20] = {0};
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    if (fucked[j] == false)
                        cur[idx++] = j;
                }
            }

            if (idx <= 2) {
                if (mx < idx) {
                    mx = idx;
                    for (int j = 0; j < idx; j++)
                        mxFucked[j] = cur[j];
                }
            } else {
                /*
                1
                5
                5
                9 4
                6 0
                4 8
                8 -8
                4 -7
                */
                int dx = inp[cur[1]].first - inp[cur[0]].first;
                int dy = inp[cur[1]].second - inp[cur[0]].second;
                int g = gcd(dx, dy);
                if (dx == 0 && dy == 0) {
                    for (int x = 0; x < n; x++)
                        printf("%d %d\n", inp[x].first, inp[x].second);
                    assert(1 == -1);
                }
                dx /= g;
                dy /= g;

                if (dy < 0)
                    dy = -dy, dx = -dx;
                bool ok = true;
                for (int j = 2; j < idx; j++) {
                    int dxx = inp[cur[j]].first - inp[cur[0]].first;
                    int dyy = inp[cur[j]].second - inp[cur[0]].second;
                    if (dxx == 0 && dyy == 0) {
                        for (int x = 0; x < n; x++)
                            printf("%d %d\n", inp[x].first, inp[x].second);
                        assert(1 == -1);
                    }
                    g = gcd(dxx, dyy);
                    dxx /= g;
                    dyy /= g;

                    if (dyy < 0)
                        dyy = -dyy, dxx = -dxx;

                    if (dx == 0 && dxx == 0)
                        continue;
                    if (dy == 0 && dyy == 0)
                        continue;

                    if (dx != dxx || dy != dyy) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    if (idx > mx) {
                        mx = idx;
                        for (int k = 0; k < idx; k++)
                            mxFucked[k] = cur[k];
                    }
                }
            }
        }

        acc += mx;
        cnt++;
        for (int i = 0; i < mx; i++) {
            // printf("round %d fucked %d\n", cnt, mxFucked[i]);
            fucked[mxFucked[i]] = true;
        }
    }

    return cnt;
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
