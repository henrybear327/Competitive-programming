class Solution
{
private:
    bool check(const string &s, int l, int r, bool hasDel)
    {
        if (l >= r)
            return true;

        if (s[l] == s[r])
            return check(s, l + 1, r - 1, hasDel);
        else {
            if (hasDel)
                return false;
            return check(s, l, r - 1, true) || check(s, l + 1, r, true);
        }
    }

public:
    bool validPalindrome(string s)
    {
        if (s.length() <= 1)
            return true;

        return check(s, 0, s.length() - 1, false);
    }
};
