// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        int sz = pattern.size();
        vector<string> ans;
        for (auto &word : words) {
            bool error = false;
            unordered_map<char, char> mapping;
            for (int i = 0; i < sz; i++) {
                if (mapping.find(word[i]) != mapping.end()) {
                    if (mapping[word[i]] != pattern[i]) {
                        error = true;
                        break;
                    }
                } else {
                    mapping[word[i]] = pattern[i];
                }
            }

            unordered_set<char> has;
            for (auto &i : mapping) {
                if (has.find(i.second) != has.end())
                    error = true;
                else
                    has.insert(i.second);
            }

            if (error == false) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
