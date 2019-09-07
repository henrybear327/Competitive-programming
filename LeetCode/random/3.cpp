class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // two pointer
        
        unordered_set<char> contained;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.length(); right++) {
            // [left, right)
            while(contained.find(s[right]) != contained.end()) {
                contained.erase(s[left]);  
                left++;
            } 
            contained.insert(s[right]);
            ans = max(ans, (int)contained.size());
        }
        
        return ans;
    }
};
