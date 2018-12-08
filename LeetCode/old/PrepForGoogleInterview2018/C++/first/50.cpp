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
    double myPow(double x, int n)
    {
        // x^n
        double base = 1;
        bool neg = n < 0;
        long long int nn = llabs((long long int)n); // wow abs(n) might overflow...
        while (nn > 0) {
            if (nn & 1)
                base = base * x;
            x *= x;
            nn >>= 1;
        }
        return neg ? 1 / base : base;
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().myPow(2.00000, -2147483648) << endl;
    return 0;
}
#endif