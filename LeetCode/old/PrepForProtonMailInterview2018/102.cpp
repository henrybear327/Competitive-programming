// :%s/^ \* //g
#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// define data structures here
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (q.size() > 0) {
            int sz = q.size();
            vector<int> res;
            for (int i = 0; i < sz; i++) {
                TreeNode *cur = q.front();
                res.push_back(cur->val);
                q.pop();
                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);
            }
            ans.push_back(res);
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
