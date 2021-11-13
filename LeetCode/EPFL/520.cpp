class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(auto &w: word) {
            if('A' <= w && w <= 'Z') {
                cnt++;
            } 
        }
        
        if(cnt == word.size() || cnt == 0 || (cnt == 1 && 'A' <= word[0] && word[0] <= 'Z'))
            return true;
        return false;
    }
};
