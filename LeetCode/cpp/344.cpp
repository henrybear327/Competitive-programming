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
    string reverseString(string s)
    {
        reverse(s.begin(), s.end());
        return s;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif