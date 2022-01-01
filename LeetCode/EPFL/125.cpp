class Solution {
public:
    bool isPalindrome(string s) {
        string newS;
        for(auto &c: s) {
            if('A' <= c && c <= 'Z') {
                newS += c - 'A' + 'a';
            } else if('a' <= c && c <= 'z') {
                newS += c;
            } else if('0' <= c && c <= '9') { // alphanumeric
                newS += c;
            }else {
                // skip
            }
        }

        for(int i = 0; i < newS.size() / 2; i++) {
            if(newS[i] != newS[newS.size() - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};
