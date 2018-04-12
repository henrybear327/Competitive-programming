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
    bool areSentencesSimilar(vector<string> &words1, vector<string> &words2,
                             vector<pair<string, string>> pairs)
    {
        if (words1.size() != words2.size())
            return false;

        map<string, vector<string>> pairing;
        for (auto i : pairs) {
            pairing[i.first].push_back(i.second);
            pairing[i.second].push_back(i.first);
        }

        int sz = words1.size();
        for (int i = 0; i < sz; i++) {
            if (pairing.count(words1[i]) > 0) {
                bool ok = false;
                for (auto j : pairing[words1[i]]) {
                    if (j == words2[i])
                        ok = true;
                }

                if (ok == true)
                    continue;
            }
            if (words1[i] != words2[i])
                return false;
        }

        return true;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
