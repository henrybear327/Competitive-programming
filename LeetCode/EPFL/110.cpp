/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool ok = true;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left = dfs(root->left) + 1;
        int right = dfs(root->right) + 1;

        if(abs(left - right) > 1)
            ok = false;

        return max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ok;
    }
};
