class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0;
        unordered_set<int> ss;
        int ans = 0;
        for (int r = 0; r < s.length(); r++) {
            while (l < r && ss.find(s[r]) != ss.end()) {
                ss.erase(s[l]);
                l++;
            }

            ss.insert(s[r]);
            ans = max(ans, (int)ss.size());
        }
        return ans;
    }
};
