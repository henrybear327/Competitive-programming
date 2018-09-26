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
    int maxProduct(vector<string> &words)
    {
        vector<int> masks;
        for (auto i : words) {
            int mask = 0;
            for (auto j : i) {
                mask |= (1 << (j - 'a'));
            }

            masks.push_back(mask);
        }

        int ans = 0;
        for (int i = 0; i < (int)masks.size(); i++) {
            for (int j = i + 1; j < (int)masks.size(); j++) {
                if ((masks[i] & masks[j]) == 0) {
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
                }
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