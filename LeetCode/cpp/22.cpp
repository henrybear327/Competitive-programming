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
private:
    void dfs(int n, int i, int l, int r, string &s, vector<string> &ans)
    {
        if (n * 2 == i) {
            ans.push_back(s);
            return;
        }

        if (l < n) {
            s += "(";
            dfs(n, i + 1, l + 1, r, s, ans);
            s.pop_back();
        }

        if (r < n && l > r) {
            s += ")";
            dfs(n, i + 1, l, r + 1, s, ans);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        string s;
        vector<string> ans;

        dfs(n, 0, 0, 0, s, ans);

        return ans;
    }
};

int main()
{
    return 0;
}