// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    void dfs(int x, int y, vector<vector<char>> &grid, int xb, int yb)
    {
        if (!(0 <= x && x < xb && 0 <= y && y < yb))
            return;
        if (grid[x][y] == '0')
            return;

        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            dfs(xx, yy, grid, xb, yb);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;

        for (int i = 0; i < (int)grid.size(); i++) {
            for (int j = 0; j < (int)grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid, grid.size(), grid[i].size());
                }
            }
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