// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    int countSubstrings(string s)
    {
        int ans = 0;

        string ns = "";
        for (int i = 0; i < (int)s.length(); i++) {
            ns += s[i];
            if (i != (int)s.length() - 1)
                ns += "$";
        }

        for (int i = 0; i < (int)ns.length(); i++) {
            int start = (ns[i] == '$' ? 1 : 0);
            for (int j = start; i + j < (int)ns.length() && i - j >= 0; j += 2) {
                if (ns[i + j] == ns[i - j]) {
                    ans++;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}