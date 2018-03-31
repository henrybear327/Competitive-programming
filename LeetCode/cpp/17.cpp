// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

static char *mapping[] = {
    "0",   "1",   "abc",  "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
}; // almost forget about this usage

/*
static const map<char, vector<string>> digitCharLookup =
        {
            {'0', {}},
            {'1', {}},
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}
        };
*/

class Solution
{
private:
    void dfs(string &digits, vector<string> &ans, int pos, string &tmp)
    {
        if (pos == (int)digits.size()) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < (int)strlen(mapping[digits[pos] - '0']); i++) {
            tmp += mapping[digits[pos] - '0'][i];
            dfs(digits, ans, pos + 1, tmp);
            tmp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        if (digits.size() > 0) {
            string tmp = "";
            dfs(digits, ans, 0, tmp);
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