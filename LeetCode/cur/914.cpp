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

/*
Input: [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2]
*/

class Solution
{
private:
    // maintain a < b property after the initial call is the key
    int gcd(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        return a == 0 ? b : gcd(b % a, a);
    }

public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> cnt;
        for (auto &i : deck) {
            cnt[i]++;
        }

        int g = 0;
        for (auto &i : cnt) {
            g = gcd(g, i.second);
        }

        return g > 1;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
