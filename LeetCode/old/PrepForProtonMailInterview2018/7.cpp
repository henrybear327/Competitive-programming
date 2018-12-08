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
    int reverse(int x)
    {
        /*
        long long rev = 0;
        bool neg = x < 0;
        x = abs(x);
        while (x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        rev = neg ? -rev : rev;

        if (INT_MIN <= rev && rev <= INT_MAX)
            return (int)rev;
        return 0;
        */

        int rev = 0;
        while (x) {
            if (rev >= 0 && INT_MAX / 10 < rev)
                return 0;
            else if (rev >= 0 && INT_MAX / 10 == rev && x % 10 > 7)
                return 0;
            else if (rev < 0 && INT_MIN / 10 < rev)
                return 0;
            else if (rev < 0 && INT_MIN / 10 == rev && x % 10 < -8)
                return 0;

            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return rev;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
