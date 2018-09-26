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
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto i : nums) {
            if (s.count(i) == 0)
                s.insert(i);
            else
                return i;
        }
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
