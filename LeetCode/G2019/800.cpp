class Solution {
private:
    string ans, cur;
    vector<int> curVal;
    int mx;
    int decode[6];
    const char* hex = "0123456789abcdef";
    
    void dfs(int depth)
    {
        if(depth == 3) {
            // cout << cur << endl;
            int diff = 0;
            for(int i = 0; i < 3; i++) {
                int va = curVal[i*2] * 16 + curVal[i*2];
                int vb = decode[i * 2] * 16 + decode[i * 2 + 1];
                diff += ((va-vb) * (va-vb));
            }
            if(diff < mx) {
                ans = cur;
                mx = diff;
                // cout << cur << " " << diff << endl;
            }
                
            return;
        }
        
        for(int i = 0; i < 16; i++) {
            cur += hex[i];
            cur += hex[i];
            curVal.push_back(i);
            curVal.push_back(i);
            dfs(depth + 1);
            curVal.pop_back();
            curVal.pop_back();
            cur.pop_back();
            cur.pop_back();
        }
    }
public:
    string similarRGB(string color) {
        for(int i = 1; i < 7; i++)
            for(int j = 0; j < 16; j++)
                if(color[i] == hex[j])
                    decode[i - 1] = j;
        
        mx = INT_MAX;
        dfs(0);
        
        return "#" + ans;
    }
};


class Solution {
    private:
    const char* hex = "0123456789abcdef";
public:
    string similarRGB(string color) {
        color = color.substr(1);
        int val[3] = {0};
        for(int i = 0; i < 6; i++) 
            for(int j = 0; j < 16; j++)
                if(hex[j] == color[i])
                    val[i / 2] = val[i / 2] * 16 + j;
            
        string ans;
        int mn = INT_MAX;
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 16; j++)
                for(int k = 0; k < 16; k++) {
                    int diff = 0;
                    int ii = i * 16 + i;
                    int jj = j * 16 + j;
                    int kk = k * 16 + k;
                    diff += (val[0] - ii) * (val[0] - ii);
                    diff += (val[1] - jj) * (val[1] - jj);
                    diff += (val[2] - kk) * (val[2] - kk);
                    
                    if(diff < mn) {
                        mn = diff;
                        ans = hex[i];
                        ans += hex[i];
                        ans += hex[j];
                        ans += hex[j];
                        ans += hex[k];
                        ans += hex[k];
                        
                        // cout << diff << " " << ans << endl;
                    }
                }
        return "#" + ans;
    }
};
