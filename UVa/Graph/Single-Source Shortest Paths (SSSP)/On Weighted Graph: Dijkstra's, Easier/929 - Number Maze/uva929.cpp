#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

inline bool ok(int x, int y, int n, int m)
{
    return (0 <= x && x < n) && (0 <= y && y < m);
}

int solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int inp[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &inp[i][j]);

    int dp[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = INF;

    dp[0][0] = inp[0][0];

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push(iii(dp[0][0], ii(0, 0)));
    while (pq.size() > 0) {
        int w = pq.top().first;
        ii u = pq.top().second;
        pq.pop();

        if (w > dp[u.first][u.second])
            continue;

        for (int i = 0; i < 4; i++) {
            int xx = u.first + dx[i];
            int yy = u.second + dy[i];

            int dist = dp[u.first][u.second] + inp[xx][yy];
            if (ok(xx, yy, n, m) && dp[xx][yy] > dist) {
                dp[xx][yy] = dist;
                pq.push(iii(dist, ii(xx, yy)));
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        printf("%d\n", solve());

    return 0;
}
