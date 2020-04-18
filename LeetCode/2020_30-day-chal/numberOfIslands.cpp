static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        
        for(int k = 0; k < 4; k++) {
            int xx = i + dx[k];
            int yy = j + dy[k];
            
            if((0 <= xx && xx < grid.size()) && (0 <= yy && yy < grid[xx].size()))
                dfs(grid, xx, yy);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};
