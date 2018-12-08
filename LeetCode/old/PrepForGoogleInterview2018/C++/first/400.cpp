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
typedef long long ll;
class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n < 10)
            return n;

        ll base = 1;
        for (int i = 1;; i++) {
            if (n - base * 9 * i < 0) {
                // this interval
                n--;
                int step = n / i;
                int rem = n % i;

                int cand = base + step;
                rem = i - 1 - rem;
                while (rem > 0 && cand > 0) {
                    cand /= 10;
                    rem--;
                }

                return cand % 10;
                break;
            } else {
                n -= base * 9 * i;
                base *= 10;
            }
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