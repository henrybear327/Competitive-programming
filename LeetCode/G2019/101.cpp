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
    bool check(TreeNode *l, TreeNode *r)
    {
        if (l == NULL && r == NULL)
            return true;
        if (l == NULL || r == NULL)
            return false;

        if (l->val == r->val) // key insight
            return check(l->left, r->right) && check(l->right, r->left);
        return false;
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return check(root->left, root->right);
    }
};
