class Solution
{
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m;

    inline bool inBound(int x, int y)
    {
        return (0 <= x && x < n) && (0 <= y && y < m);
    }
    void dfs(vector<vector<int>> &image, int x, int y, int newColor,
             vector<vector<bool>> &seen)
    {
        if (seen[x][y])
            return;
        seen[x][y] = true;

        // cout << x << " " << y << endl;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            // cout << "xx " << xx << " " << yy << endl;

            if (inBound(xx, yy) && image[xx][yy] == image[x][y])
                dfs(image, xx, yy, newColor, seen);
        }
        image[x][y] = newColor;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor)
    {
        n = image.size();
        if (n > 0)
            m = image[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        dfs(image, sr, sc, newColor, seen);
        return image;
    }
};