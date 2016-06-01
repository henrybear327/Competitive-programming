#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int dist(int x, int y, int a, int b)
{
    int dx = x - a;
    int dy = y - b;
    return dx * dx + dy * dy;
}

typedef map<ii, int> data;
data loc[10010]; // for every x-coor, store location and count
set<ii> sloc;
int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);

            loc[x][(ii(x, y))]++;
        }

        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r);
            if (sloc.find(ii(x, y)) != sloc.end())
                continue;

            for (int j = (x - r >= 0 ? x - r : 0);
                 j <= (x + r <= 10000 ? x + r : 10000); j++) {
                int dy = sqrt(r * r - (j - x) * (j - x));
                int uppery = y + dy, lowery = y - dy;

                auto it_begin = loc[j].lower_bound(ii(j, lowery));
                auto it_end = loc[j].upper_bound(ii(j, uppery));

                loc[j].erase(it_begin, it_end);
            }
        }

        int ans = 0;
        for (int i = 0; i < 10010; i++) {
            for (auto j : loc[i])
                ans += j.second;
        }
        printf("%d\n", ans);
    }
    return 0;
}
