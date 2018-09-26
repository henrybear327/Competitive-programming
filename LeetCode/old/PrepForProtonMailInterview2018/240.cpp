// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
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
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        if (n == 0)
            return false;
        int m = matrix[0].size();
        if (m == 0)
            return false;

        int x = n - 1, y = 0;
        while (x >= 0 && y < m) {
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target)
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
