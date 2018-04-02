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

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        // [1, n + 1)
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            int ret = guess(mid);
            if (ret == 0)
                return mid;
            else if (ret == -1)
                r = mid;
            else
                l = mid;
        }

        return l;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif