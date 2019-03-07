class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        reverse(digits.begin(), digits.end());
        for (auto &i : digits)
            i = i + carry, carry = i / 10, i %= 10;
        if (carry > 0)
            digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};