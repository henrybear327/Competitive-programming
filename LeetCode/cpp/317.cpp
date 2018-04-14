#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?
typedef pair<int, int> ii;
class Solution
{
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    bool ok(int x, int y, int n, int m)
    {
        return (0 <= x && x < n) && (0 <= y && y < m);
    }

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &dp,
             vector<vector<int>> &cnt, int n, int m, int x, int y)
    {
        queue<ii> q;
        map<ii, int> inqueue;

        q.push(ii(x, y));
        inqueue[ii(x, y)] = 0;
        while (q.size() > 0) {
            ii cur = q.front();
            q.pop();
            int level = inqueue[cur];
            dp[cur.first][cur.second] += level;

            for (int i = 0; i < 4; i++) {
                int xx = cur.first + dx[i];
                int yy = cur.second + dy[i];
                if (ok(xx, yy, n, m) && inqueue.count(ii(xx, yy)) == 0 &&
                    grid[xx][yy] == 0) {
                    q.push(ii(xx, yy));
                    inqueue[ii(xx, yy)] = level + 1;
                    cnt[xx][yy]++;
                }
            }
        }
    }

public:
    int shortestDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> cnt(n, vector<int>(m, 0)); // WA: reachbility test!!

        // cal dp
        int buildings = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    bfs(grid, dp, cnt, n, m, i, j);
                    buildings++;
                }

        // get answer
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && cnt[i][j] == buildings)
                    mn = min(mn, dp[i][j]);
            }

        return mn == INT_MAX ? -1 : mn;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
