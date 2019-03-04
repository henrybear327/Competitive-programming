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
    int ans = 0;
    void dfs(TreeNode *root, double target)
    {
        if (root == NULL)
            return;
        if (fabs(root->val - target) < fabs(ans - target)) {
            ans = root->val;
        }
        dfs(root->left, target);
        dfs(root->right, target);
    }

public:
    int closestValue(TreeNode *root, double target)
    {
        ans = root->val;
        dfs(root, target);
        return ans;
    }
};
