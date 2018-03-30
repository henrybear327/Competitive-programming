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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef pair<int, int> ii; // v, x

class Solution
{
private:
    ii dfs(TreeNode *root)
    {
        if (root == NULL)
            return ii(0, 0);

        ii l = dfs(root->left);
        ii r = dfs(root->right);

        return ii(root->val + l.second + r.second,
                  max(l.first, l.second) + max(r.first, r.second));
    }

public:
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        ii ret = dfs(root);
        return max(ret.first, ret.second);
    }
};

int main()
{
    return 0;
}