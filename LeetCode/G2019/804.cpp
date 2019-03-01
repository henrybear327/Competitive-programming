class Solution {
private:
    const char* code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> cnt;
        
        for(auto i : words) {
            string converted;
            for(auto j : i) {
                converted += code[j - 'a'];
            }
            cnt.insert(converted);
        }
        
        return cnt.size();
    }
};
