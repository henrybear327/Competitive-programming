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

class Solution
{
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    void dfs(vector<vector<int>> &grid, int x, int y, int &cnt,
             vector<vector<bool>> &seen)
    {
        if (seen[x][y])
            return;
        seen[x][y] = true;

        int neighbor = 0;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if ((0 <= xx && xx < (int)grid.size()) &&
                (0 <= yy && yy < (int)grid[xx].size()) && grid[xx][yy] == 1) {
                neighbor++;
                dfs(grid, xx, yy, cnt, seen);
            }
        }

        cnt += 4 - neighbor;
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        // for every block in the island
        // count adjacent blocks for every one of them
        int cnt = 0;
        vector<vector<bool>> seen;
        for (int i = 0; i < (int)grid.size(); i++) {
            vector<bool> tmp((int)grid[i].size(), false);
            seen.push_back(tmp);
        }

        for (int i = 0; i < (int)grid.size(); i++)
            for (int j = 0; j < (int)grid[i].size(); j++)
                if (grid[i][j] == 1 && seen[i][j] == false)
                    dfs(grid, i, j, cnt, seen);

        return cnt;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif