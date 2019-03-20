class Solution
{
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m;
    bool dfs(int x, int y, const string &word, int idx,
             vector<vector<bool>> &seen, vector<vector<char>> &board)
    {
        // cout << "in " << x << " " << y << endl;
        if (idx == word.length() - 1)
            return true;
        seen[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if ((0 <= xx && xx < n) && (0 <= yy && yy < m) && seen[xx][yy] == false &&
                board[xx][yy] == word[idx + 1]) {
                // cout << "next " << xx << " " << yy << ": " << x << " " << y << endl;
                if (dfs(xx, yy, word, idx + 1, seen, board))
                    return true;
            }
        }
        // cout << "out " << x << " " << y << endl;
        seen[x][y] = false; // WTF bro
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // cout << "start" << endl;
        if (word.length() == 0)
            return true;

        n = board.size();
        if (n == 0)
            return false;
        m = board[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> seen(n, vector<bool>(m, false));
                    if (dfs(i, j, word, 0, seen, board))
                        return true;
                }
            }
        return false;
    }
};
