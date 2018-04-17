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
        int ret = 1;
        if (root->left && root->left->val == root->val + 1)
            ret = max(ret, l + 1);
        if (root->right && root->right->val == root->val + 1)
            ret = max(ret, r + 1);

        ans = max(ans, ret);
        return ret;
    }

public:
    int longestConsecutive(TreeNode *root)
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
