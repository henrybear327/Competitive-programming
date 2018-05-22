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
    int ans;
    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        if (root->left != NULL && root->left->val == root->val) {
            l++;
        } else {
            ans = max(ans, l);
            l = 0;
        }

        if (root->right != NULL && root->right->val == root->val) {
            r++;
        } else {
            ans = max(ans, r);
            r = 0;
        }

        ans = max(ans, l + r);

        return max(l, r); // return the max length of left or right only
        // since the root node can only entend on one of them
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        ans = 0;

        dfs(root);

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif