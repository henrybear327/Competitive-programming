class Solution
{
private:
    bool isSame(int cnt[], int pCnt[])
    {
        for (int i = 0; i < 26; i++)
            if (cnt[i] != pCnt[i])
                return false;
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.length(), m = p.length();
        int cnt[26] = {0}, pCnt[26] = {0};
        for (int i = 0; i < m; i++)
            pCnt[p[i] - 'a']++;

        vector<int> ans;
        if (n < m)
            return ans;

        for (int i = 0; i < m; i++)
            cnt[s[i] - 'a']++;

        if (isSame(cnt, pCnt))
            ans.push_back(0);
        for (int i = m; i < n; i++) {
            cnt[s[i] - 'a']++;
            cnt[s[i - m] - 'a']--;

            if (isSame(cnt, pCnt))
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};
