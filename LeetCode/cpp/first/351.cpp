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

// handle special cases first
// [], "", ...
// range of input?
class Solution
{
private:
    const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    inline bool inBound(int x, int y)
    {
        return (0 <= x && x < 3) && (0 <= y && y < 3);
    }

    void dfs(int &m, int &n, int &ans, bool used[3][3], int depth, int x, int y)
    {
        if (inBound(x, y) == false) // out of bound
            return;

        if (used[x][y]) // used
            return;

        if (m <= depth && depth <= n) // record if in range
            ans++;

        if (depth == n) // no need to recurse
            return;

        used[x][y] = true;

        // surrounding box
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                dfs(m, n, ans, used, depth + 1, x + i, y + j);

        // knight
        for (int i = 0; i < 8; i++)
            dfs(m, n, ans, used, depth + 1, x + dx[i], y + dy[i]);

        // horizontal
        if (y + 2 < 3 && used[x][y + 1] == true)
            dfs(m, n, ans, used, depth + 1, x, y + 2);
        if (y - 2 >= 0 && used[x][y - 1] == true)
            dfs(m, n, ans, used, depth + 1, x, y - 2);
        // vertical
        if (x + 2 < 3 && used[x + 1][y] == true)
            dfs(m, n, ans, used, depth + 1, x + 2, y);
        if (x - 2 >= 0 && used[x - 1][y] == true)
            dfs(m, n, ans, used, depth + 1, x - 2, y);
        // diagnal
        if (x + 2 < 3 && y + 2 < 3 && used[x + 1][y + 1] == true)
            dfs(m, n, ans, used, depth + 1, x + 2, y + 2);
        if (x + 2 < 3 && y - 2 >= 0 && used[x + 1][y - 1] == true)
            dfs(m, n, ans, used, depth + 1, x + 2, y - 2);
        if (x - 2 >= 0 && y + 2 < 3 && used[x - 1][y + 1] == true)
            dfs(m, n, ans, used, depth + 1, x - 2, y + 2);
        if (x - 2 >= 0 && y - 2 >= 0 && used[x - 1][y - 1] == true)
            dfs(m, n, ans, used, depth + 1, x - 2, y - 2);

        used[x][y] = false;
    }

public:
    int numberOfPatterns(int m, int n) // [m, n]
    {
        int ans = 0;
        bool used[3][3];
        memset(used, 0, sizeof(used));

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                dfs(m, n, ans, used, 1, i, j);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
