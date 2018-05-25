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
class Solution
{
public:
    bool isStrobogrammatic(string num)
    {
        int n = num.size();
        for (int i = 0; i < n / 2; i++)
            if (num[i] == '1' || num[i] == '8') {
                continue;
            } else if (num[i] == '6' || num[i] == '9') {
                if (num[i] == '6' && num[n - 1 - i] != '9')
                    return false;
                if (num[i] == '9' && num[n - 1 - i] != '6')
                    return false;
            } else {
                return false;
            }
        return true;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
