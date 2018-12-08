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
    bool isPowerOfTwo(int n)
    {
        if (n < 0)
            return false;
        return __builtin_popcount(n) == 1;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif