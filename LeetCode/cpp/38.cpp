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
    string countAndSay(int n)
    {
        if (n == 0)
            return "";

        string ans = "1";

        for (int i = 1; i < n; i++) {
            string nxt = "";
            int cnt = 1;
            char what = ans[0];
            for (int j = 1; j < (int)ans.size(); j++) {
                if (ans[j] != ans[j - 1]) {
                    nxt += to_string(cnt) + what;

                    cnt = 1;
                    what = ans[j];
                } else
                    cnt++;
            }

            nxt += to_string(cnt) + what;
            ans = nxt;
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif