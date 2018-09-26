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
        int n = (int)s.length();
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - 1 - i]);
        return s;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif