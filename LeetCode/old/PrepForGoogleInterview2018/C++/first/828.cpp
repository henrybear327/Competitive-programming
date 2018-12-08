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
const int MOD = 1e9 + 7;
class Solution
{
private:
    void inc(long long &ans, int amount)
    {
        ans = (ans + amount) % MOD;
    }

public:
    int uniqueLetterString(string S)
    {
        int n = S.length();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int lb = i, rb = i;
            bool doneL = false, doneR = false;
            for (int j = 1; j < n; j++) {
                if (doneL == false && i - j >= 0) {
                    if (S[i] != S[i - j]) {
                        lb = i - j;
                    } else {
                        doneL = true;
                    }
                }

                if (doneR == false && i + j < n) {
                    if (S[i] != S[i + j]) {
                        rb = i + j;
                    } else {
                        doneR = true;
                    }
                }
            }

            inc(ans, (i - lb + 1) * (rb - i + 1));
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().uniqueLetterString("ABC") << endl;
    return 0;
}
#endif