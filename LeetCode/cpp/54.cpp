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
    const int dx[4] = {0, 1, 0, -1}; // RDLU
    const int dy[4] = {1, 0, -1, 0};
    void dfs(vector<int> &ans, vector<vector<bool>> &seen,
             vector<vector<int>> &matrix, int x, int y, int dir)
    {
        if (seen[x][y])
            return;
        seen[x][y] = true;
        ans.push_back(matrix[x][y]);

        for (int i = 0; i < 4; i++) {
            int d = (dir + i) % 4;
            int xx = x + dx[d];
            int yy = y + dy[d];

            if ((0 <= xx && xx < (int)matrix.size()) &&
                (0 <= yy && yy < (int)matrix[xx].size())) {
                dfs(ans, seen, matrix, xx, yy, d);
            }
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;

        vector<vector<bool>> seen;
        for (int i = 0; i < (int)matrix.size(); i++) {
            vector<bool> tmp(matrix[i].size(), false);
            seen.push_back(tmp);
        }
        dfs(ans, seen, matrix, 0, 0, 0);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif