#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool check(int xx, int yy, int n, int m)
{
    return (0 <= xx && xx < n) && (0 <= yy && yy < m);
}

const int N = 250;
int g[N][N];
int seen[N][N];
int bak[N][N];

int bfs(int n, int m)
{
    memset(seen, -1, sizeof(seen));
    queue<ii> q;
    int mx = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 1) {
                q.push({i, j});
                seen[i][j] = 0;
            }

    while (q.size() > 0) {
        ii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = cur.first + dx[i];
            int yy = cur.second + dy[i];

            if (check(xx, yy, n, m) && seen[xx][yy] == -1) {
                seen[xx][yy] = seen[cur.first][cur.second] + 1;
                q.push({xx, yy});
                mx = max(mx, seen[xx][yy]);
            }
        }
    }

    return mx;
}

int bfs2(int n, int m, int x, int y)
{
    queue<ii> q;
    q.push({x, y});
    int seen2[n][m];
    memset(seen2, -1, sizeof(seen2));
    seen2[x][y] = 0;
    while (q.size() > 0) {
        ii cur = q.front();
        q.pop();

        int dist = seen2[cur.first][cur.second];
        for (int i = 0; i < 4; i++) {
            int xx = cur.first + dx[i];
            int yy = cur.second + dy[i];

            if (check(xx, yy, n, m) && seen2[xx][yy] == -1 &&
                seen[xx][yy] > dist + 1) {
                seen2[xx][yy] = dist + 1;
                q.push({xx, yy});
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mx = max(mx, seen2[i][j] == -1 ? seen[i][j] : seen2[i][j]);
    return mx;
}

int solve()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        char inp[m + 3];
        scanf("%s", inp);
        for (int j = 0; j < m; j++) {
            g[i][j] = inp[j] == '0' ? 0 : 1;
        }
    }

    int mx = bfs(n, m);
    if (mx == 0)
        return 0;

    memcpy(bak, seen, sizeof(bak));

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 0) {
                g[i][j] = 1;
                memcpy(seen, bak, sizeof(seen));
                ans = min(ans, bfs2(n, m, i, j));
                g[i][j] = 0;
            }
        }

    return ans == INT_MAX ? 0 : ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++)
        printf("Case #%d: %d\n", i, solve());
    return 0;
}
