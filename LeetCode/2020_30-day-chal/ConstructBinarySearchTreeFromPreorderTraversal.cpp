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
    // [lb, rb)
    int idx = 0;
    TreeNode* dfs(vector<int>& preorder, int lb, int rb) {
        if(idx == preorder.size())
            return NULL;
        if(!(lb <= preorder[idx] && preorder[idx] < rb))
            return NULL;
        
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        node->left = dfs(preorder, lb, node->val);
        node->right = dfs(preorder, node->val + 1, rb);
        
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, INT_MIN, INT_MAX);
    }
};
