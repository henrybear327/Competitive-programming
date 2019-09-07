class Solution {
public:
    int numDecodings(string s) {
        int dp[s.length() + 1] = {0};
        dp[0] = 1;
        s = " " + s;
        for(int i = 1; i < s.length(); i++) {
            int one = (s[i] == '0') ? 0 : dp[i - 1];
            int val = (s[i - 1] - '0') * 10 + (s[i] - '0');
            int two = (i - 2 >= 0 && s[i - 1] != '0' && val <= 26) ? dp[i - 2] : 0;
            
            dp[i] = one + two;
        }
        
        return dp[s.length() - 1];
    }
};

// 1 0 1 1 
// 1 1 1 2

// 1 1
// 1 2

// 1 1 0
// 1 2 1

// 1 2 2 6 
// 1 2 2
// 12 2
// 1 22
// 1 2 3  
