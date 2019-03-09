class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mapping;
        unordered_map<char, char> reverseMapping;
        for (int i = 0; i < (int)s.size(); i++) {
            if (mapping.find(s[i]) == mapping.end()) {
                if (reverseMapping.find(t[i]) == reverseMapping.end())
                    mapping[s[i]] = t[i], reverseMapping[t[i]] = s[i];
                else
                    return false;
            } else {
                if (mapping[s[i]] != t[i] || reverseMapping[t[i]] != s[i])
                    return false;
            }
        }

        return true;
    }
};
