#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    ll val[x][y][z];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++) {
                scanf("%lld", &val[i][j][k]);
                if (j > 0)
                    val[i][j][k] += val[i][j - 1][k];
            }

    for (int k = 0; k < z; k++)
        for (int i = 0; i < x; i++)
            for (int j = y - 1; j >= 0; j--) {
                ll upper = (i - 1 >= 0 ? val[i - 1][j][k] : 0);
                ll self = val[i][j][k];

                val[i][j][k] = upper + self;
            }

#ifdef DEBUG
    for (int k = 0; k < z; k++)
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                printf("%lld%c", val[i][j][k], j == y - 1 ? '\n' : ' ');
#endif

    ll mx = LLONG_MIN;
    for (int lx = 0; lx < x; lx++)
        for (int ly = 0; ly < y; ly++)
            for (int rx = lx; rx < x; rx++)
                for (int ry = ly; ry < y; ry++) {
                    ll sum = 0;
                    for (int k = 0; k < z; k++) {
                        ll self = val[rx][ry][k];
                        ll lowerLeft = ly - 1 >= 0 ? val[rx][ly - 1][k] : 0;
                        ll upperRight = lx - 1 >= 0 ? val[lx - 1][ry][k] : 0;
                        ll upperLeft =
                            lx - 1 >= 0 && ly - 1 >= 0 ? val[lx - 1][ly - 1][k] : 0;
                        ll tmp = self - upperRight - lowerLeft + upperLeft;

                        // do kadane on tmp
                        sum += tmp;
                        mx = max(mx, sum); // leave it here if you want to get the max value, even when negative -> test case 2
                        if (sum < 0)
                            sum = 0;
                    }
                }
    printf("%lld\n", mx);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
        if (ncase)
            printf("\n");
    }

    return 0;
}
