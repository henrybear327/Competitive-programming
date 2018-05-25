class Solution
{
public:
    int shortestDistance(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        int val = 0;
        // int cntBuilding = 0;
        vector<vector<int>> sum = grid;
        // vector<vector<int>>cnt(m, vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // cntBuilding++;
                    help(grid, sum, i, j, m, n, val);
                    val--;
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == val) {
                    res = min(res, sum[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }

private:
    void help(vector<vector<int>> &grid, vector<vector<int>> &sum, int i, int j,
              int m, int n, int &val)
    {
        pair<int, int> pp(i, j);
        q.push(pp);
        int count = q.size();
        int level = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        /* Key! Use count! */
        while (count > 0) {
            pair<int, int> p = q.front();
            q.pop();
            count--;
            for (int k = 0; k < 4; k++) {
                int ii = p.first + dx[k];
                int jj = p.second + dy[k];
                if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] == val) {
                    grid[ii][jj] = val - 1;
                    sum[ii][jj] += level;
                    // cnt[ii][jj]++;
                    pair<int, int> ppp(ii, jj);
                    q.push(ppp);
                }
            }
            if (count == 0) {
                count = q.size();
                level++;
            }
        }
    }
    queue<pair<int, int>> q;
};
