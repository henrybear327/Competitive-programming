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
    int countSubstrings(string s)
    {
        int ans = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            // center on number
            for (int j = 0; i + j < (int)s.length() && i - j >= 0; j++) {
                if (s[i + j] != s[i - j])
                    break;
                ans++;
            }

            // center on space (space to the right of the number)
            for (int j = 0; i - j >= 0 && i + 1 + j < (int)s.length(); j++) {
                if (s[i - j] != s[i + 1 + j])
                    break;
                ans++;
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
