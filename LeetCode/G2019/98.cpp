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
    bool check(TreeNode *root, long long int left, long long int right)
    {
        if (root == NULL)
            return true;

        if (left <= root->val && root->val <= right)
            return check(root->left, left, root->val - 1LL) &&
                   check(root->right, root->val + 1LL, right);
        return false;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return check(root, INT_MIN, INT_MAX);
    }
};
