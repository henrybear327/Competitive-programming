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
    bool dfs(TreeNode *s, TreeNode *t, bool isChecking)
    {
        if (s == NULL && t == NULL) // WTF
            return true;
        if (s == NULL || t == NULL)
            return false;

        if (s->val == t->val) {
            bool ret = dfs(s->left, t->left, true) && dfs(s->right, t->right, true);
            if (ret)
                return ret;
        }

        if (isChecking)
            return false;
        return dfs(s->left, t, false) || dfs(s->right, t, false);
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        return dfs(s, t, false);
    }
};