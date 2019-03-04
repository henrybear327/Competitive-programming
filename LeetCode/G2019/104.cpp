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
    int ans;
    void dfs(TreeNode *root, int depth)
    {
        if (root == NULL) {
            ans = max(ans, depth);
            return;
        }
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }

public:
    int maxDepth(TreeNode *root)
    {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};

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
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};
