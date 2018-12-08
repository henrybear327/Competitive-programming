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
    string toLowerCase(string str)
    {
        string res;
        for (auto i : str)
            if ('A' <= i && i <= 'Z')
                res += i - 'A' + 'a';
            else
                res += i;
        return res;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
