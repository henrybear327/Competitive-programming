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
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
};

// class Solution
// {
// private:
//     int n, m;
//     bool ok(int x, int y)
//     {
//         return (0 <= x && x < n) && (0 <= y && y < m);
//     }
//
// public:
//     bool isToeplitzMatrix(vector<vector<int>> &matrix)
//     {
//         n = matrix.size();
//         m = matrix[0].size();
//         for (int i = 0; i < n; i++) {
//             int x = i, y = 0;
//             while (ok(x, y)) {
//                 if (matrix[i][0] != matrix[x][y])
//                     return false;
//
//                 x++;
//                 y++;
//             }
//         }
//
//         for (int j = 0; j < m; j++) {
//             int x = 0, y = j;
//             while (ok(x, y)) {
//                 if (matrix[0][j] != matrix[x][y])
//                     return false;
//
//                 x++;
//                 y++;
//             }
//         }
//
//         return true;
//     }
// };

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
