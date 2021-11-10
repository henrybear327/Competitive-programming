class Solution {
public:
    int firstUniqChar(string s) {
        int state[26] = {0};
        for(int i = 0; i < s.size(); i++) {
            int code = s[i] - 'a';
            if(state[code] == 0) {
                // first time
                state[code] = i + 1;
            } else if(state[code] > 0) { 
                // second time
                state[code] = -1;
            } else { // -1
                continue;
            }
        }
        
        int ret = s.size() + 1;
        for(int i = 0; i < 26; i++) {
            if(state[i] > 0 && ret > state[i]) {
                ret = state[i];
            }
        }
        
        return ret == s.size() + 1 ? -1 : ret - 1;
    }
};
