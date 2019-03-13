class Solution
{
private:
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        if (grid[x][y] != '1')
            return;
        grid[x][y] = '2';

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

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1')
                    dfs(i, j, grid), ans++;
        return ans;
    }
};
