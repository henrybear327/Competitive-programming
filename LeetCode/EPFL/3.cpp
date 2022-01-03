class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        int l = 0;
        set<char> seen;
        for(int r = 0; r < s.size(); r++) {
            if(seen.count(s[r]) == 1) {
                while(l < r && s[l] != s[r]) {
                    seen.erase(s[l]);
                    l++;
                }
                if(l != r) {
                    l++;
                }
            } else {
                seen.insert(s[r]);
            }

            // printf("%d %d\n", l, r);
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
