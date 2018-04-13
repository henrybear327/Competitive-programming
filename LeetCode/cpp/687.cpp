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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    int dfs(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;

        int ret = 0;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        if (root->left && root->left->val == root->val)
            ret = max(ret, l + 1);
        if (root->right && root->right->val == root->val)
            ret = max(ret, r + 1);
        if (root->left && root->right && root->right->val == root->val &&
            root->val == root->left->val)
            ans = max(ans, l + 1 + r + 1); // KEY!! case [5,5,5,5,5,5]

        ans = max(ans, ret);
        return ret;
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
