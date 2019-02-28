auto fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // WTF is this problem statement...
        int cnt[26] = {0};
        for(auto i : magazine)
            cnt[i - 'a']++;
        for(auto i : ransomNote)
            if(cnt[i - 'a'] > 0)
                cnt[i - 'a']--;
            else
                return false;
        return true;
    }
};
