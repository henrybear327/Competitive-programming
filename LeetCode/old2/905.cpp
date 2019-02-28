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
    vector<int> sortArrayByParity(vector<int> &A)
    {
        sort(A.begin(), A.end(),
             [](const int a, const int b) -> bool { return a % 2 < b % 2; });
        return A;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
