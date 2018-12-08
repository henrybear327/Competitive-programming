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
private:
    TreeNode *ans, *cur;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;

        if (ans == NULL)
            ans = cur = new TreeNode(root->val);
        else {
            cur->right = new TreeNode(root->val);
            cur = cur->right;
        }

        dfs(root->left);
        dfs(root->right);
    }

public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        ans = NULL;
        dfs(root);
        root->left = NULL;
        root->right = ans->right;
        return;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
