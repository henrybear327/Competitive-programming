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

public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        queue<ii> q;
        int n = rooms.size();
        if (n == 0)
            return;
        int m = rooms[0].size();
        if (m == 0)
            return;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    q.push(ii(i, j));
                }
            }
        }

        while (q.size() > 0) {
            ii cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int xx = cur.first + dx[i];
                int yy = cur.second + dy[i];

                if (ok(xx, yy, n, m) && rooms[xx][yy] == INT_MAX) {
                    rooms[xx][yy] = rooms[cur.first][cur.second] + 1;
                    q.push(ii(xx, yy));
                }
            }
        }
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif