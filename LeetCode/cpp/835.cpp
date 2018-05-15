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
    // up right left down
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    int n, m;

    int check(vector<vector<int>> &res, vector<vector<int>> &B)
    {
        int ret = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (res[i][j] == B[i][j] && res[i][j] == 1)
                    ret++;
        return ret;
    }

    bool in(int x, int y)
    {
        return (0 <= x && x < n) && (0 <= y && y < m);
    }

    int move(vector<vector<int>> &A, vector<vector<int>> &B, int moveX,
             int moveY)
    {
        int ret = 0;
        // vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int xx = i - moveX;
                int yy = j - moveY;

                if (in(xx, yy)) {
                    // res[i][j] = A[xx][yy];
                    if (A[xx][yy] == B[i][j] && A[xx][yy] == 1)
                        ret++;
                }
            }
        }

        // return check(res, B);
        return ret;
    }

public:
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        n = A.size();
        if (n == 0)
            return 0;
        m = A[0].size();
        if (m == 0)
            return 0;

        int ans = 0;
        for (int i = -n + 1; i < n; i++) {
            for (int j = -m + 1; j < m; j++) {
                ans = max(ans, move(A, B, i, j));
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