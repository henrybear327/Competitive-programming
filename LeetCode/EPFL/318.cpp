class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mx = 0;
        
        vector<int> masks; // can be optimized to keep the mask and length, where length is the longest one's value!
        for(auto &word: words) {
            int mask = 0;
            for(auto &c: word) {
                int num = c - 'a';
                mask |= (1 << num);
            }
            masks.push_back(mask);
        }
        
        // 001100
        // 110000
        
        // 001100
        // 011000
        int n = words.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if((masks[i] & masks[j]) == 0) {
                    mx = max(mx, (int)words[i].length() * (int)words[j].length());
                }
            }
        }
        
        return mx;
    }
};
