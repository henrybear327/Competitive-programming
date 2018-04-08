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
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> check;
        for (auto i : nums)
            if (check.count(i) != 0)
                return true;
            else
                check.insert(i);
        return false;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif