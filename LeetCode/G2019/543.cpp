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

        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        ans = max(ans, l + r);

        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};