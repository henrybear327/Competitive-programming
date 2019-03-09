class Solution
{
public:
    bool areSentencesSimilar(vector<string> &words1, vector<string> &words2,
                             vector<pair<string, string>> pairs)
    {
        if (words1.size() != words2.size())
            return false;

        unordered_map<string, unordered_set<string>> mapping;
        for (auto i : pairs) {
            mapping[i.first].insert(i.second); // mapping might be a->b, c, d!!!!!
            mapping[i.second].insert(i.first);
        }

        for (int i = 0; i < (int)words1.size(); i++) {
            if (words1[i] == words2[i])
                continue;
            if (mapping[words1[i]].count(words2[i]) > 0)
                continue;
            return false;
        }
        return true;
    }
};
