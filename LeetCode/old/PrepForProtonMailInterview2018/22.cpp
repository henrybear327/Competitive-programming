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
private:
    void dfs(int left, int right, int n, string cur, vector<string> &ans)
    {
        if (left > n || right > n)
            return;
        if (left == n && right == n) {
            ans.push_back(cur);
            return;
        }
        if (right == n)
            return;
        if (left < right) // not enough opening paranthesis before closing ones
            return;

        dfs(left + 1, right, n, cur + "(", ans);
        dfs(left, right + 1, n, cur + ")", ans);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        dfs(0, 0, n, "", ans);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
