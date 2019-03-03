class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int r = grid.size();
        if(r == 0)
            return 0;
        int c = grid[0].size();
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(grid[i][j] == 1) {
                    ans += 4;
                    for(int k = 0; k < 4; k++) {
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if((0 <= xx && xx < r) && (0 <= yy && yy < c) && grid[xx][yy] == 1)
                            ans--;
                    }
                }
        return ans ;
    }
};
