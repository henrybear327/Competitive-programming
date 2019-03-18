class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> data;
        for (auto &i : strs) {
            string orig = i;
            sort(i.begin(), i.end());
            data[i].push_back(orig);
        }

        vector<vector<string>> ans;
        for (auto &i : data)
            ans.push_back(i.second);
        return ans;
    }
};
