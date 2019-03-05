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
    int sum = 0;
    void dfs(TreeNode *root, bool isLeft)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL && isLeft)
            sum += root->val;
        dfs(root->left, true);
        dfs(root->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        sum = 0;
        dfs(root, false);
        return sum;
    }
};