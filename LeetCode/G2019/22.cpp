class Solution
{
private:
    string tmp;
    vector<string> ans;
    void dfs(int l, int r, int n)
    {
        if (l < r) // This guarantees that ) will always have a ( to match, so no
            // need to check afterwards
            return;
        if (l > n / 2) // OOPS
            return;
        if (l + r == n) {
            ans.push_back(tmp);

            return;
        }

        tmp.push_back('(');
        dfs(l + 1, r, n);
        tmp.pop_back();

        tmp.push_back(')');
        dfs(l, r + 1, n);
        tmp.pop_back();
    }

public:
    vector<string> generateParenthesis(int n)
    {
        dfs(0, 0, n * 2);
        return ans;
    }
};