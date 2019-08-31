class Solution
{
private:
    vector<int> cache;
    bool wordBreak(string s, vector<string> &wordDict, int idx)
    {
        if (idx == s.length()) // terminating condition
            return true;

        if (cache[idx] != -1)
            return cache[idx];

        for (auto i : wordDict) {
            int len = s.length() - idx;
            if (len < i.length())
                continue;
            bool ok = true;
            for (int j = 0; j < i.length(); j++) {
                if (s[idx + j] != i[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (wordBreak(s, wordDict, idx + i.length())) {
                    return cache[idx] = true;
                }
            }
        }

        return cache[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        cache = vector<int>(s.length(), -1);
        return wordBreak(s, wordDict, 0);
    }
};
