class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() > b.length();
        });

        unordered_map<string, int> dp;
        for (auto i : words)
            dp[i] = 1;

        // ["a","b","ba","bca","bda","bdca"]
        // ["a", "ab", "abc", "abcd", "abcde"]

        for (auto i : words) {
            // cout << "i = " << i << endl;
            for (int j = 0; j < i.length(); j++) {
                // [0, j) (j, i.length() - 1]
                auto str = i.substr(0, j) + i.substr(j + 1);
                // cout << str << endl;
                if (auto it = dp.find(str); it != dp.end()) {
                    it->second = max(dp[i] + 1, it->second);
                }
            }
        }

        int ans = 0;
        for (auto i : dp)
            ans = max(ans, i.second);

        return ans;
    }
};
