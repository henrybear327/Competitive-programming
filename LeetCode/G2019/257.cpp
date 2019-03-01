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
    vector<int> path;
    string printPath()
    {
        string ret;
        int sz = path.size();
        for(int i = 0; i < sz; i++) {
            ret += to_string(path[i]);
            ret += i == sz - 1 ? "" : "->";
        }
        return ret;
    }
    
    void dfs(TreeNode* root, vector<string> &ans)
    {
        if(root == NULL)
            return;
        
        path.push_back(root->val);

        if(root->right == NULL && root->left == NULL) {
            string ret = printPath();
            ans.push_back(ret);
            path.pop_back();
            return;
        }
                
        dfs(root->left, ans);
        dfs(root->right, ans);
        
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, ans);
        return ans;
    }
};
