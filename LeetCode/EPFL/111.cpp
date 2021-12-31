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
    void dfs(TreeNode* root, int depth, int &ans) {
        if(root == NULL) {
            return;
        }

        if(root->left == NULL && root->right == NULL) {
            ans = min(ans, depth);
        }

        dfs(root->left, depth + 1, ans);
        dfs(root->right, depth + 1, ans);
    }
public:
    int minDepth(TreeNode* root) {
        int ans = INT_MAX;

        dfs(root, 1, ans);

        return ans == INT_MAX ? 0 : ans;
    }
};

