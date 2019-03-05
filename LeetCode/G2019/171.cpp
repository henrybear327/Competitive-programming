class Solution
{
public:
    int titleToNumber(string s)
    {
        int result = 0;
        for (auto i : s) {
            result *= 26;
            result += i - 'A' + 1;
        }

        return result;
    }
};