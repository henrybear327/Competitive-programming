class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
            return true;
        int m = matrix[0].size();
        if(m == 0)
            return true;
        
        // Life can be a whole lot eaiser
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                if(matrix[i - 1][j - 1] != matrix[i][j])
                    return false;
        
//         for(int i = 0; i < n; i++) {
//             for(int j = 1; j < m && i + j < n; j++) {
//                 // (i, j) -> (i + j, j)
//                 if(matrix[i + j - 1][j - 1] != matrix[i + j][j]) {
//                     return false;
//                 }
//             }
//         }
        
//         for(int j = 1; j < m; j++) {
//             for(int i = 1; i < n && i + j < m; i++) {
//                 // (i, j) -> (i, j + i)
//                 if(matrix[i - 1][j + i - 1] != matrix[i][j + i])
//                     return false;
//             }
//         }
        
        return true;
    }
};
