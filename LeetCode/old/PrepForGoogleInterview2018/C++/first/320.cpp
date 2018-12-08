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
    vector<string> generateAbbreviations(string word)
    {
        vector<string> ans;
        int n = word.size();
        if (n == 0) {
            ans.push_back("");
            return ans;
        }
        for (int i = 0; i < (1 << n); i++) {
            bool state[n];
            for (int j = 0; j < n; j++) {
                state[j] = ((i >> j) & 1);
            }

            string res = "";
            bool active = false;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (state[j]) {
                    if (active) {
                        active = false;
                        res += to_string(cnt);
                        cnt = 0;
                    } else {
                    }
                    res += word[j];
                } else {
                    if (active) {
                    } else {
                        active = true;
                    }
                    cnt++;
                }
            }

            if (cnt > 0) {
                res += to_string(cnt);
            }

            ans.push_back(res);
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