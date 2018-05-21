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
    inline int update(vector<vector<int>> &board, int x, int y)
    {
        int cnt = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) // WTF?
                    continue;

                int xx = x + i;
                int yy = y + j;
                if ((0 <= xx && xx < (int)board.size()) &&
                    (0 <= yy && yy < (int)board[0].size())) {
                    if (board[xx][yy] == 1)
                        cnt++;
                }
            }
        }

        if (board[x][y] == 1) {
            if (cnt < 2)
                return 0;
            if (cnt > 3)
                return 0;
            return 1;
        } else {
            if (cnt == 3)
                return 1;
            return 0;
        }
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        if (board.size() == 0)
            return;

        vector<vector<int>> copy = board;
        for (int i = 0; i < (int)board.size(); i++) {
            for (int j = 0; j < (int)board[i].size(); j++) {
                board[i][j] = update(copy, i, j);
            }
        }
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif