class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for(const auto &str : strs) {
            string orig = str;
            sort(orig.begin(), orig.end());
            
            ans[orig].push_back(str);
        }
        
        auto ret = vector<vector<string>>();
        for(const auto &i : ans)
            ret.push_back(i.second);
        
        return ret;
    }
};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
