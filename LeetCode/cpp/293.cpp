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
    vector<string> generatePossibleNextMoves(string s)
    {
        vector<string> ans;
        int n = s.length();

        for (int i = 0; i < n - 1; i++) {
            char nxt = s[i] == '+' ? '-' : '+';
            if (s[i] == '+' && s[i] == s[i + 1]) {
                string tmp = s;
                tmp[i] = tmp[i + 1] = nxt;
                ans.push_back(tmp);
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