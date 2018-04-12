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
    // S = A + A + ... + A
    // B is substring of S
    int repeatedStringMatch(string A, string B)
    {
        int lenA = A.length();
        int lenB = B.length();
        string S = A;
        int cnt = 1;

        // for every starting point of A
        for (int i = 0; i < lenA; i++) {
            bool ok = true;
            // we try to match B with S, append if needed
            for (int j = 0; j < lenB; j++) {
                if (i + j < (int)S.length() && B[j] == S[i + j])
                    continue;
                else if (i + j < (int)S.length()) {
                    ok = false;
                    break;
                } else {
                    S += A;
                    cnt++;
                    j--;
                }
            }

            if (ok)
                return cnt;
        }

        return -1;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif