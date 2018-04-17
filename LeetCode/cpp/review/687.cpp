#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
private:
    int dfs(int &ans, TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = dfs(ans, root->left);
        int r = dfs(ans, root->right);
        int ret = 0; // oneside max length
        if (root->left && root->left->val == root->val)
            ret = max(ret, l + 1);
        if (root->right && root->right->val == root->val)
            ret = max(ret, r + 1);

        ans = max(ret, ans);
        if (root->left && root->right && root->left->val == root->right->val &&
            root->left->val == root->val)
            ans = max(ans, l + r + 2);
        return ret;
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        int ans = 0;
        dfs(ans, root);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
