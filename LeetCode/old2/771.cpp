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
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, int> sCnt;
        unordered_set<char> jCnt;
        for (auto i : J)
            jCnt.insert(i);

        for (auto i : S)
            sCnt[i]++;

        int ans = 0;
        for (auto i : jCnt)
            if (sCnt.find(i) != sCnt.end())
                ans += sCnt[i];

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
