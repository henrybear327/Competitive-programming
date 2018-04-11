#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif
/*
["NumMatrix","sumRegion","update","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[3,2,2],[2,1,4,3]]
["NumMatrix","sumRegion","update","sumRegion"]
[[[[1]]],[0,0,0,0],[0,0,-1],[0,0,0,0]]
["NumMatrix","sumRegion","update","update","sumRegion","update","update","sumRegion","sumRegion","update","update"]
[[[[-3,-4,1,-8,-2,2,4,-3,-6,-7],[6,-3,6,-4,-6,8,-2,4,-6,-3]]],[0,7,0,8],[1,8,5],[1,2,-2],[1,2,1,6],[0,2,-8],[1,5,0],[0,9,0,9],[1,8,1,9],[1,1,-7],[1,1,1]]
["NumMatrix","sumRegion","update","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[3,2,2],[2,1,4,3]]
*/

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
// (a, b) is just the place to +/- val
typedef long long ll;

struct BIT2D {
    vector<vector<int>> bit;
    int n, m;
    void init(int _n, int _m)
    {
        n = _n + 3;
        m = _m + 3;
        bit = vector<vector<int>>(n, vector<int>(m, 0));
    }

    ll sum(int a, int b)
    {
        a += 2;
        b += 2;
        ll s = 0;
        for (int i = a; i > 0; i -= (i & -i))
            for (int j = b; j > 0; j -= (j & -j))
                s += bit[i][j];
        return s;
    }

    void add(int a, int b, ll x)
    {
        a += 2;
        b += 2;
        for (int i = a; i < n; i += (i & -i))
            for (int j = b; j < m; j += (j & -j))
                bit[i][j] += x;
    }
} bit;

class NumMatrix
{
private:
    vector<vector<int>> matrix;

public:
    NumMatrix(vector<vector<int>> _matrix)
    {
        matrix = _matrix;

        int n = matrix.size();
        if (n == 0)
            return;
        int m = matrix[0].size();
        bit.init(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bit.add(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val)
    {
        int diff = val - matrix[row][col];
        bit.add(row, col, diff);
        matrix[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ret = bit.sum(row2, col2) - bit.sum(row1 - 1, col2) -
                  bit.sum(row2, col1 - 1) + bit.sum(row1 - 1, col1 - 1);
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */

#ifdef LOCAL
int main()
{
    return 0;
}
#endif