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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // use BST property
        if(root == NULL)
            return NULL;
        
        int vp = p->val;
        int vq = q->val;
        if(vp > vq)
            swap(vp, vq);
        
        if(vp <= root->val && root->val <= vq) // the first splitting node
            return root;
        else if(vp < root->val && vq < root->val)
            return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// private:
//     TreeNode* ans;
//     bool lca(TreeNode* root, TreeNode* p, TreeNode *q) {
//         if(root == NULL)
//             return false;
        
//         bool found = false;
//         if(root == p || root == q)
//             found = true;
//         bool l = lca(root->left, p, q);
//         bool r = lca(root->right, p, q);
        
//         if(found && (l || r)) { // self + one child -> self
//             ans = root;
//             return true;
//         }
//         if(l && r) { // both children -> self
//             ans = root;
//             return true;
//         }
        
//         return found || r || l;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // only one query per test case
//         // why bother to use the LCA data structure??
        
//         ans = NULL;
//         lca(root, p, q);
//         return ans;
//     }
// };
