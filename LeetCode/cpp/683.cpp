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
    int kEmptySlots(vector<int> &flowers, int k)
    {
        set<int> s;
        int day = 1;
        for (auto i : flowers) {
            s.insert(i);
            auto it = s.find(i);
            auto before = it, after = it;

            if (before != s.begin()) {
                before--;
                // printf("day %d, %d\n", day, *it - *before - 1);
                if (k == *it - *before - 1) {
                    return day;
                }
            }

            after++;
            if (after != s.end()) {
                // printf("day %d, %d\n", day, *after - *it - 1);
                if (k == *after - *it - 1) {
                    return day;
                }
            }

            day++;
        }

        return -1;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif