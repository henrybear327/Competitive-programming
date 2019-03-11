class Solution
{
private:
    bool ok(char c)
    {
        return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z');
    }

public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.length() - 1;
        for (auto &i : s)
            if ('A' <= i && i <= 'Z')
                i = i - 'A' + 'a';

        while (l <= r) {
            while (l <= r && !ok(s[l]))
                l++;
            while (l <= r && !ok(s[r]))
                r--;

            if (l <= r) {
                if (s[l] != s[r])
                    return false;
                else
                    l++, r--;
            }
        }

        return true;
    }
};