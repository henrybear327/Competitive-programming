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

const int Base = 137;
const int M = 1000000007;

typedef long long ll;

struct RollingHash {
    vector<ll> p, h;
    void init(string inp) // build polynomial table and hash value
    {
        p.resize(inp.length() + 1);
        h.resize(inp.length() + 1);

        p[0] = 1; // b to the ith power
        for (int i = 1; i <= (int)inp.length(); i++) {
            h[i] = (h[i - 1] * Base % M + inp[i - 1]) % M; // hash value
            p[i] = p[i - 1] * Base % M;
        }
    }

    ll get_hash(int l, int r) // [l, r] of the inp string array
    {
        return ((h[r + 1] - (h[l] * p[r - l + 1])) % M + M) % M;
    }
};

/*
"baaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbaba"
"baaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbababaaabbbaba"
*/

class Solution
{
private:
public:
    int repeatedStringMatch(string A, string B)
    {
        string orig = A;
        while (A.length() < B.length())
            A += orig;
        A += orig;
        // cout << A.length() << " " << B.length() << endl;

        RollingHash hA, hB;
        hA.init(A);
        hB.init(B);
        for (int i = 0; i + B.length() <= A.length(); i++) {
            cout << i << endl;
            if (hA.get_hash(i, i + B.length() - 1) ==
                hB.get_hash(0, B.length() - 1)) {
                if (A.substr(i, B.length()) != B)
                    continue;
                // cout << i + B.length() << " " << A.length() - orig.length() << endl;
                if (i + B.length() <= A.length() - orig.length())
                    return (A.length() - orig.length()) / orig.length();
                return A.length() / orig.length();
            }
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