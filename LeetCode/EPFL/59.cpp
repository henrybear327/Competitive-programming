class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        
        int x = 0, y = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int next = 0;
        for(int i = 1; i <= n * n; i++) {
            ret[x][y] = i;
            
            // printf("put %d %d\n", x, y);
            
            for(int j = 0; j < 4; j++) {
                int xx = x + dx[next];
                int yy = y + dy[next];
                
                // printf("try %d %d %d\n", x, y, next);
                
                if(0 <= xx && xx < n && 0 <= yy && yy < n && ret[xx][yy] == 0) {
                    x = xx;
                    y = yy;
                    
                    break;
                } else {
                    next++;
                    next %= 4;
                }
            }
        }
        
        return ret;
    }
};
