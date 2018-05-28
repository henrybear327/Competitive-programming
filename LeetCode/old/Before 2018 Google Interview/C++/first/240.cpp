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
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        // {
        //     // upperbound can be limited by binary search
        //     for (int i = 0; i < (int)matrix.size(); i++) {
        //         bool ret = binary_search(matrix[i].begin(), matrix[i].end(),
        //         target); if (ret)
        //             return ret;
        //     }
        // }

        // {
        //     // search upperbound (col 0)
        //     int l = 0, r = matrix.size();
        //     {
        //         while (r - l > 1) {
        //             int mid = (l + r) / 2;
        //             if (matrix[mid][0] <= target)
        //                 l = mid;
        //             else
        //                 r = mid;
        //         }
        //     }

        //     // search each row
        //     for (int i = 0; i < r; i++) {
        //         int lb = 0, rb = matrix[i].size();
        //         while (rb - lb > 1) {
        //             int mid = (lb + rb) / 2;
        //             if (matrix[i][mid] <= target)
        //                 lb = mid;
        //             else
        //                 rb = mid;
        //         }
        //         if (matrix[i][lb] == target)
        //             return true;
        //     }
        // }

        // [n - 1][0] <-> [0][m - 1]
        // only move right or up (vice versa)
        // right is for > and up is for <
        // Nice!
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        int x = n - 1;
        int y = 0;
        while (0 <= x && y < m) {
            if (target == matrix[x][y])
                return true;
            else if (target < matrix[x][y])
                x--;
            else
                y++;
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