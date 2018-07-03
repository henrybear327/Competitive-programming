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
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (auto i : nums)
            ret ^= i;
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
