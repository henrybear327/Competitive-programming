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
    string orderlyQueue(string S, int k)
    {
        if (k == 1) {
            string best = S;
            int sz = S.size();
            for (int i = 0; i < sz; i++) {
                rotate(S.begin(), next(S.begin()), S.end());
                best = min(best, S);
            }
            /*
            for (int i = 0; i < sz; i++) {
                if (S < best)
                    best = S;
                char c = S.front();
                S = S.substr(1);
                S.push_back(c);
            }
            */
            return best;
        } else {
            sort(S.begin(), S.end());
            return S;
        }
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
