class Solution
{
private:
    vector<int> ans;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    inline bool inBound(int x, int y, vector<vector<int>> &matrix)
    {
        return (0 <= x && x < matrix.size()) && (0 <= y && y < matrix[0].size());
    }

    void dfs(int x, int y, int dir, vector<vector<int>> &matrix,
             vector<vector<bool>> &seen)
    {
        if (inBound(x, y, matrix) == false)
            return;

        ans.push_back(matrix[x][y]);
        seen[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int newDir = (dir + i) % 4;
            int xx = x + dx[newDir];
            int yy = y + dy[newDir];

            if (inBound(xx, yy, matrix) && seen[xx][yy] == false) {
                dfs(xx, yy, newDir, matrix, seen);
                break;
            }
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return ans;
        int m = matrix[0].size();

        vector<vector<bool>> seen(n, vector<bool>(m, false));
        dfs(0, 0, 0, matrix, seen);
        return ans;
    }
};