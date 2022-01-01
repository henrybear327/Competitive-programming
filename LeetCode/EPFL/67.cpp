class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ret;

        int i = 0, j = 0;
        int carry = 0;
        while(i < a.size() || j < b.size()) {
            int sum = carry;
            carry = 0;
            if(i < a.size()) {
                sum += a[i] - '0';
                i++;
            }
            if(j < b.size()) {
                sum += b[j] - '0';
                j++;
            }

            ret.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        if(carry > 0)
            ret.push_back(carry + '0');
        reverse(ret.begin(), ret.end());

        return ret;
    }
};
