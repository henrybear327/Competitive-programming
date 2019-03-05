class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> cnt;
        for (auto i : s)
            cnt[i]++;
        for (auto i : t)
            cnt[i]--;
        for (auto i : cnt)
            if (i.second != 0)
                return false;
        return true;
    }
};