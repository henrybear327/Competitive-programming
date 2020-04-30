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
static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();
class Solution {
private:
    int mx = INT_MIN;
    int dfs(TreeNode* root) {
        if(root == NULL)
            return 0;
    
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        mx = max(mx, right + root->val + left);
        
        int ret = root->val;
        ret = max(ret, root->val + left);
        ret = max(ret, root->val + right);
        
        mx = max(mx, ret);
        
        return ret;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};
