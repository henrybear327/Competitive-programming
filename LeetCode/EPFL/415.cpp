class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry = 0;
        
        int i = num1.size() - 1, j = num2.size() - 1;
        while(i >= 0 || j >= 0) {
            int sum = carry;
            carry = 0;
            if(i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if(j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            
            carry = sum / 10;
            sum %= 10;
            
            ans += to_string(sum);
        }
        
        if(carry > 0) {
            ans += to_string(carry);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
