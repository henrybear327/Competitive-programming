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
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 != NULL && root2 != NULL) {
            // cout << root1->val << " " << root2->val << endl;

            if (root1->val != root2->val)
                return false;

            auto ret1 = flipEquiv(root1->left, root2->left) &&
                        flipEquiv(root1->right, root2->right);
            if (ret1)
                return true;

            auto ret2 = flipEquiv(root1->right, root2->left) &&
                        flipEquiv(root1->left, root2->right);
            if (ret2)
                return true;
        }

        return false;
    }
};
