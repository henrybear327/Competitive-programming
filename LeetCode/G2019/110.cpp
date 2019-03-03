/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool ok;
    int dfs(TreeNode* root, int depth)
    {
        if(root == NULL)
            return depth;
        int l = dfs(root->left, depth + 1);
        int r = dfs(root->right, depth + 1);
        
        if(abs(r - l) > 1) 
            ok = false;
        
        return max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        ok = true;
        dfs(root, 0);
        
        return ok;
    }
};
