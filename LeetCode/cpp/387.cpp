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

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int pos[26];
        memset(pos, -1, sizeof(pos));

        for (int i = 0; i < (int)s.length(); i++) {
            int idx = s[i] - 'a';
            if (pos[idx] == -1) // first occurrence
                pos[idx] = i;
            else if (pos[idx] >= 0) // second occurrence
                pos[idx] = -2;
        }

        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (pos[i] >= 0) {
                ans = min(ans, pos[i]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif