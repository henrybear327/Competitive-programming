// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    int n, m;
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        if (grid[x][y] != '1')
            return;
        grid[x][y] = 0;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if ((0 <= xx && xx < n) && (0 <= yy && yy < m)) {
                dfs(xx, yy, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        if (n == 0)
            return 0;
        m = grid[0].size();
        if (m == 0)
            return 0;

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
