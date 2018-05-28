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
    int reverse(long long int x)
    {
        bool neg = x < 0;
        long long int rev = 0;
        if (neg)
            x = -x;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        if (rev > INT_MAX)
            return 0;
        return neg ? -rev : rev;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif