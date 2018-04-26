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

// observation
// same value on front and back -> can't win
// otherwise, winable
class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        map<int, int> cnt; // -1 -> not candidate

        int n = fronts.size();
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) { // not cand
                cnt[fronts[i]] = -1;
            } else {
                if (cnt[fronts[i]] != -1)
                    cnt[fronts[i]]++;
                if (cnt[backs[i]] != -1)
                    cnt[backs[i]]++;
            }
        }

        for (auto i : cnt) {
            if (i.second == -1)
                continue;

            return i.first;
        }

        return 0;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif