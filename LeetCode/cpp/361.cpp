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
public:
    int maxKilledEnemies(vector<vector<char>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        if (m == 0)
            return 0;
        int horizontal[n][m], vertical[n][m];
        memset(horizontal, 0, sizeof(horizontal));
        memset(vertical, 0, sizeof(vertical));

        for (int i = 0; i < n; i++) {
            int acc = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'W') {
                    acc = 0;
                } else if (grid[i][j] == 'E') {
                    acc++;
                } else
                    horizontal[i][j] += acc;
            }

            acc = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') {
                    acc = 0;
                } else if (grid[i][j] == 'E') {
                    acc++;
                } else
                    horizontal[i][j] += acc;
            }
        }

        for (int j = 0; j < m; j++) {
            int acc = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 'W') {
                    acc = 0;
                } else if (grid[i][j] == 'E') {
                    acc++;
                } else
                    vertical[i][j] += acc;
            }

            acc = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (grid[i][j] == 'W') {
                    acc = 0;
                } else if (grid[i][j] == 'E') {
                    acc++;
                } else
                    vertical[i][j] += acc;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, horizontal[i][j] + vertical[i][j]);
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
