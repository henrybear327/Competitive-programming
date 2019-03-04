class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < (int)s.size(); i++)
            if (t[i] != s[i])
                return t[i];
        return t.back();
    }
};
