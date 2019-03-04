class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        // possile char type: A, a?
        unordered_map<char, int> cnt;
        for (auto i : s)
            cnt[i]++;

        int odd = 0;
        for (auto i : cnt)
            if (i.second % 2 == 1)
                odd++;
        return odd <= 1;
    }
};
