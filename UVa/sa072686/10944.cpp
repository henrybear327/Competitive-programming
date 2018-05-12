#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int oo = 0x3f3f3f3f;

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        int sx = -1, sy = -1;
        vector<ii> loc;
        for (int i = 0; i < n; i++) {
            char str[m + 2];
            scanf("%s", str);
            for (int j = 0; j < m; j++) {
                if (str[j] == 'L') {
                    sx = i;
                    sy = j;
                } else if (str[j] == '.') {
                } else {
                    loc.push_back(ii(i, j));
                }
            }
        }
        loc.push_back(ii(sx, sy));
        int pts = loc.size();

        // get dist
        int dist[pts][pts];
        for (int i = 0; i < pts; i++)
            fill(dist[i], dist[i] + pts, oo);

        for (int i = 0; i < pts; i++)
            for (int j = 0; j < pts; j++)
                dist[i][j] = max(abs(loc[i].first - loc[j].first),
                                 abs(loc[i].second - loc[j].second));

        // for (int i = 0; i < pts; i++)
        //     for (int j = 0; j < pts; j++) {
        //         printf("%3d%c", dist[i][j], j == pts - 1 ? '\n' : ' ');
        //     }

        // dp
        // init
        pts--; // #pts is the starting point
        int dp[pts][(1 << pts)];
        for (int i = 0; i < pts; i++) {
            fill(dp[i], dp[i] + (1 << pts), oo);
            dp[i][1 << i] = dist[i][pts];
            // printf("i %d %d\n", i, dp[i][1 << i]);
        }
        for (int j = 0; j < (1 << pts); j++) {
            for (int i = 0; i < pts; i++) {
                for (int k = 0; k < pts; k++) {
                    if (((j >> k) & 1) == 1 && k != i) {
                        // printf("i %d j %d k %d, (%d) %d %d\n", i, j, k, j - (1 << k),
                        //        dp[i][j], dp[k][j - (1 << k)] + dist[i][k]);
                        dp[i][j] = min(dp[i][j], dp[k][j - (1 << i)] + dist[i][k]);
                    }
                }
            }
        }

        // for (int i = 0; i < pts; i++) {
        //     for (int j = 0; j < (1 << pts); j++) {
        //         printf("i %d j %d %d\n", i, j, dp[i][j]);
        //     }
        // }

        int mx = oo;
        for (int i = 0; i < pts; i++)
            mx = min(mx, dp[i][(1 << pts) - 1] + dist[pts][i]);
        printf("%d\n", mx == oo ? 0 : mx); // WA: might have no nuts
    }

    return 0;
}
