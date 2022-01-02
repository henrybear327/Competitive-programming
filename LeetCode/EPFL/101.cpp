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
    bool check(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL)
            return true;
        
        if(left != NULL && right != NULL) {
            if(left->val == right->val) {
                return (check(left->left, right->right) && check(left->right, right->left));
            }
        }

        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return check(root->left, root->right);
    }
};
