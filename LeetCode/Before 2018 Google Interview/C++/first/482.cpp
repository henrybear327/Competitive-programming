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
    // from back
    string licenseKeyFormatting(string S, int K)
    {
        string ans = "";
        int cnt = 0;
        for (int i = (int)S.length() - 1; i >= 0; i--) {
            if (S[i] == '-')
                continue;
            if (cnt > 0 && cnt % K == 0)
                ans += "-";
            if ('a' <= S[i] && S[i] <= 'z')
                S[i] = S[i] - 'a' + 'A';
            ans += S[i];
            cnt++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // from front
    // string licenseKeyFormatting(string S, int K)
    // {
    //     stringstream ss;
    //     ss.str(S);

    //     string ans = "", token, concat = "";
    //     while (getline(ss, token, '-')) {
    //         cout << token << endl;
    //         concat += token;
    //     }

    //     int len = concat.length();
    //     for (int i = 0; i < len; i++)
    //         if ('a' <= concat[i] && concat[i] <= 'z')
    //             concat[i] = concat[i] - 'a' + 'A';

    //     for (int i = 0; i < len;) {
    //         if (i == 0 && len % K > 0) {
    //             ans += concat.substr(i, len % K);
    //             i += len % K;
    //         } else {
    //             ans += (i > 0 ? "-" : "") + concat.substr(i, K);
    //             i += K;
    //         }
    //     }

    //     return ans;
    // }
};

#ifdef LOCAL
int main()
{
    string str = "5F3Z-2e-9-w";
    int k = 3;
    cout << Solution().licenseKeyFormatting(str, k) << endl;
    return 0;
}
#endif