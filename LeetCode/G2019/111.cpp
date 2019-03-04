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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        // return min(1 + minDepth(root->left), 1 + minDepth(root->right)); // wrong
        // [1, 2]

        int ans = INT_MAX;
        if (root->left != NULL)
            ans = min(ans, 1 + minDepth(root->left));
        if (root->right != NULL)
            ans = min(ans, 1 + minDepth(root->right));

        return ans == INT_MAX ? 1 : ans; // bug: leaf node issue!
    }
};
