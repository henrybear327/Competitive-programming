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
    vector<string> readBinaryWatch(int num)
    {
        // 4, 6
        vector<string> ans;
        for (int i = 0; i < (1 << 10); i++) {
            if (__builtin_popcount(i) != num)
                continue;
            int hour = 0x0000000F & i;
            int minute = (i >> 4) & 0x0000003F;

            char str[10];
            if (hour >= 12) {
                continue;
            }
            if(minute >= 60) {
                continue;
            }
            sprintf(str, "%d:%02d", hour, minute);
            ans.push_back(str);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif