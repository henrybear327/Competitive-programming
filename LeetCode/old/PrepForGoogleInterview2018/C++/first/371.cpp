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
// simply do RTL adder lol
class Solution
{
public:
    int getSum(int a, int b)
    {
        int ans = 0, carry = 0;
        for (int i = 0; i < 32; i++) {
            int a1 = (a >> i) & 1;
            int b1 = (b >> i) & 1;

            int val = a1 ^ b1 ^ carry;
            carry = (a1 && b1) || (a1 && carry) || (b1 && carry);

            if (val)
                ans |= (1 << i);
        }
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().getSum(3, 5) << endl;
    return 0;
}
#endif