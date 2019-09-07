class Solution {
public:
    string minWindow(string s, string t) {
        // two pointer
        unordered_map<char, int> cnt;
        int zero = 0;
        for(auto i : t)
            cnt[i]++;
        
        int l = 0;
        string ans = s + s;
        for(int r = 0; r < s.length(); r++) {
            if(cnt.find(s[r]) != cnt.end()) {
                cnt[s[r]]--;
                if(cnt[s[r]] == 0)
                    zero++;
            }
            
            while(zero == cnt.size()) {
                if(r - l + 1 < ans.size())
                    ans = s.substr(l, r - l + 1);
                
                if(cnt.find(s[l]) != cnt.end()) {
                    if(cnt[s[l]] == 0)
                        zero--;
                    cnt[s[l]]++;
                }
                l++;
            }
        }
        
        return ans == s + s ? "" : ans; 
    }
};
