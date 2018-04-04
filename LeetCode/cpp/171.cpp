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

class Solution
{
public:
    int titleToNumber(string s)
    {
        int ans = 0;
        int base = 1;
        reverse(s.begin(), s.end());
        for (auto i : s) {
            int val = i - 'A' + 1;
            ans += base * val;
            base *= 26;
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