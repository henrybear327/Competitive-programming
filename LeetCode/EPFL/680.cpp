class Solution {
private:
    bool ok(string s) {
        for(int i = 0; i < s.size() / 2; i++)
            if(s[i] != s[s.size() - i - 1])
                return false;
        return true;
    }
public:
    bool validPalindrome(string s) {
        // abcaacbba
        // 012345678
        //   ^   ^
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != s[s.size() - i - 1]) {
                return ok(s.substr(i + 1, s.size() - 1 - i - i)) || ok(s.substr(i, s.size() - 1 - i - i));
            }
        }
        
        return true;
    }
};
