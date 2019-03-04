class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int r = A.size();
        if (r == 0)
            return A;
        int c = A[0].size();

        for (int i = 0; i < r; i++)
            reverse(A[i].begin(), A[i].end());
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                A[i][j] = !A[i][j];

        return A;
    }
};
