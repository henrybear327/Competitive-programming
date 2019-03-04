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
    TreeNode* root;
    TreeNode* dfs(int l, int r, vector<int> &nums)
    {
        // cout << l << " " << r << endl;
        if(r - l < 0)
            return NULL;
        int mid = (l + r) / 2;
        
        TreeNode* newNode = new TreeNode(nums[mid]);
        if(root == NULL)
            root = newNode;
        newNode->left = dfs(l, mid - 1, nums);
        newNode->right = dfs(mid + 1, r, nums);
        
        return newNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        root = NULL;
        root = dfs(0, nums.size() - 1, nums);
        return root;
    }
};
