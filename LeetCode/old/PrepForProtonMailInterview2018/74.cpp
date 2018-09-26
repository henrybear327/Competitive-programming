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

        int l = 0, r = n * m; // [l, r)
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            // mid = x * n + y
            int x = mid / m;
            int y = mid % m;

            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] < target)
                l = mid;
            else
                r = mid;
        }

        return matrix[l / m][l % m] == target;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
