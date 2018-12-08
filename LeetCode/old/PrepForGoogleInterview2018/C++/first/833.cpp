#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?
class Solution
{
public:
    string findReplaceString(string S, vector<int> &indexes,
                             vector<string> &sources, vector<string> &targets)
    {
        unordered_map<int, pair<string, int>> replacement;
        for (unsigned int i = 0; i < indexes.size(); i++) {
            if (S.substr(indexes[i], sources[i].length()) == sources[i]) {
                replacement[indexes[i]] = make_pair(targets[i], sources[i].length());
            }
        }

        string ans;
        for (unsigned int i = 0; i < S.length(); i++) {
            if (replacement.count(i) > 0) {
                ans += replacement[i].first;
                i += replacement[i].second - 1;
            } else {
                ans += S[i];
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