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

typedef long long int ll;
class Solution
{
public:
    // observation
    // even numbers will all have 2, so just focus on how many 5s are there
    // 2 * 5 = 10, so just cnt the factors of each number and look for 2 and 5
    // 5, 5*5, 5*5*5, ... that's all you need to count
    int trailingZeroes(int n)
    {
        int ans = 0;
        for (int i = 5; i <= n; i *= 5)
            ans += n / 5;
        return ans;
    }
};

// handle special cases first
// [], "", ...

#ifdef LOCAL
int main()
{
    return 0;
}
#endif