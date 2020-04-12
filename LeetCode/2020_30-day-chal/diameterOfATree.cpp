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
    int dfs(TreeNode* root, TreeNode* parent, int &mx) {
        if(root == NULL) 
            return 0;
        int left = dfs(root->left, root, mx);
        int right = dfs(root->right, root, mx);
        
        mx = max(mx, left + right); // diameter from leaf to leaf
        
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // 拔拔樂
        // 2 DFS
        // DP
        
        int mx = 0;
        dfs(root, NULL, mx);
        return mx;
    }
};
