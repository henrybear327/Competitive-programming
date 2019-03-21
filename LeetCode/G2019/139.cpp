class Solution
{
private:
    int dfs(const string &s, int idx, unordered_set<string> &words,
            vector<int> &ok)
    {
        if (idx == s.length())
            return 1;
        if (ok[idx] != -1)
            return ok[idx];

        for (auto &i : words) {
            if (idx + i.length() <= s.length() && s.substr(idx, i.length()) == i) {
                if (dfs(s, idx + i.length(), words, ok)) {
                    ok[idx] = 1;
                    return 1;
                }
            }
        }

        return ok[idx] = 0;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words;
        for (auto &i : wordDict)
            words.insert(i);

        vector<int> ok(s.length(), -1);
        return dfs(s, 0, words, ok) == 0 ? false : true;
    }
};
