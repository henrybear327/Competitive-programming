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
    string maskPII(string S)
    {
        int n = S.length();
        int isEmail = -1;
        deque<char> extract;
        for (int i = 0; i < n; i++) {
            if ('A' <= S[i] && S[i] <= 'Z')
                S[i] = S[i] - 'A' + 'a';
            if (S[i] == '@')
                isEmail = i;
            if ('0' <= S[i] && S[i] <= '9')
                extract.push_back(S[i]);
        }

        if (isEmail != -1) {
            // cout << isEmail << endl;
            string masking = string(1, S[0]) + "*****" + string(1, S[isEmail - 1]);
            // cout << masking << endl;
            return masking + "@" + S.substr(isEmail + 1);
        } else {
            string ans = "";
            if (extract.size() > 10) {
                ans += "+";
                while (extract.size() > 10) {
                    // ans += extract.front();
                    ans += "*";
                    extract.pop_front();
                }
                ans += "-";
            }

            for (int i = 0; i < (int)extract.size(); i++) {
                if (i <= 5)
                    ans += "*";
                else
                    ans += extract[i];
                if (i == 2 || i == 5)
                    ans += "-";
            }
            return ans;
        }
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().maskPII("LeetCode@LeetCode.com") << endl;
    cout << Solution().maskPII("1(234)567-890") << endl;
    return 0;
}
#endif