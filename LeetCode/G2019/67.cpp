class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans;
        int carry = 0;
        for (int i = 0; i < max(a.size(), b.size()); i++) {
            int v1 = i < a.length() ? a[i] - '0' : 0;
            int v2 = i < b.length() ? b[i] - '0' : 0;

            int sum = v1 + v2 + carry;
            ans += to_string(sum % 2);
            carry = sum / 2;
        }

        if (carry == 1)
            ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
