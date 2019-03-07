class Solution {
public:
    bool isStrobogrammatic(string num) {
        // 0 1 2 3 4 5 6 7 8 9
        // 0 1         9   8 6
        int conversion[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        
        string ans = num;
        for(auto &i : ans) {
            if(conversion[i - '0'] == -1)
                return false;
            i = conversion[i - '0'] + '0';
        }
        reverse(ans.begin(), ans.end());
        
        // cout << ans << " " << num << endl;
        return ans == num;
    }
};