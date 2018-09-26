#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

/*
[["a","a"]]
"aaa"

Not allowed!!
*/

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
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int xsize, ysize;
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &seen, string word,
             int pos, int x, int y)
    {
        if (seen[x][y])
            return false;
        seen[x][y] = true;

        if ((int)word.length() == pos)
            return true;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if ((0 <= xx && xx < xsize) && (0 <= yy && yy < ysize)) {
                if (board[xx][yy] == word[pos]) {
                    bool ret = dfs(board, seen, word, pos + 1, xx, yy);
                    if (ret)
                        return ret;
                }
            }
        }

        seen[x][y] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.length() == 0)
            return false;

        xsize = board.size();
        if (xsize > 0)
            ysize = board[0].size();

        vector<vector<bool>> seen;
        for (int i = 0; i < xsize; i++) {
            vector<bool> inp(ysize, false);
            seen.push_back(inp);
        }

        for (int i = 0; i < xsize; i++) {
            for (int j = 0; j < ysize; j++) {
                if (board[i][j] == word[0]) {
                    bool ret = dfs(board, seen, word, 1, i, j);
                    if (ret)
                        return true;
                }
            }
        }

        return false;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif