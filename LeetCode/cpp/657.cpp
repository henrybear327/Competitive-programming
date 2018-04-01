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
    bool judgeCircle(string moves)
    {
        string dir = "UDLR";
        int cnt[4] = {0};
        for (auto i : moves) {
            for (int j = 0; j < 4; j++) {
                if (i == dir[j]) {
                    cnt[j]++;
                }
            }
        }

        return cnt[0] == cnt[1] && cnt[2] == cnt[3];
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif