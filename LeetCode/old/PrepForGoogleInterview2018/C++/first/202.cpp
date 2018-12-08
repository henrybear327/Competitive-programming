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
    // Floyd Cycle detection (fast and slow pointers!!) -> what a solution
    bool isHappy(int n)
    {
        int sum = 0;
        unordered_set<int> s;
        while (1) {
            while (n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (s.find(sum) != s.end())
                break;
            s.insert(sum);
            n = sum;
            sum = 0;
        }

        return s.find(1) != s.end();
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif