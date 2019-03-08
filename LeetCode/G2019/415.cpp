class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string ans;
        int carry = 0;
        for (int i = 0; i < max(num1.size(), num2.size()); i++) {
            int sum = carry;
            if (i < num1.size())
                sum += num1[i] - '0';
            if (i < num2.size())
                sum += num2[i] - '0';

            ans += (sum % 10) + '0';
            carry = sum / 10;
        }

        if (carry == 1)
            ans += '1';
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
