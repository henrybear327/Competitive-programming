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
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;

        vector<int> rem;
        while (n > 0) {
            rem.push_back(n % 3);
            n /= 3;
        }

        for (int i = 0; i < (int)rem.size() - 1; i++)
            if (rem[i] != 0)
                return false;
        return rem[(int)rem.size() - 1] == 1;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif