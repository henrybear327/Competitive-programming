#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
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

// handle special cases first
// [], "", ...
// range of input?
class Solution
{
private:
    // bottom up
    int ans = 0;
    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        int mx = 1;
        if (root->left && root->left->val == root->val + 1)
            mx = max(mx, l + 1);
        if (root->right && root->right->val == root->val + 1)
            mx = max(mx, r + 1);

        ans = max(mx, ans);

        return mx;
    }

    // top down
    int dfs(TreeNode *root, TreeNode *parent, int mx)
    {
        if (root == NULL)
            return mx;

        if (parent != nullptr && root->val == parent->val + 1)
            mx++; // extent the value from parent
        else
            mx = 1; // reset mx value to self only
        return max(mx, max(dfs(root->left, root, mx), dfs(root->right, root, mx)));
    }

public:
    int longestConsecutive(TreeNode *root)
    {
        // bottom up
        // ans = 0;
        // dfs(root);
        // return ans;

        // top down
        return dfs(root, nullptr, 0);

        // WA:
        // You can't do it directly!
        // the case below, node 4 will ret 4 to 3, and then GG
        /*
        1
         \
          3
           \
            4
           / \
          9   5
        (ret = 4)
        */
        // if (root == NULL)
        //     return 0;

        // int mx = 1;
        // if (root->left) {
        //     int ret = longestConsecutive(root->left);
        //     mx = max(mx, ret + (root->left->val == root->val + 1 ? 1 : 0));
        // }

        // if (root->right) {
        //     int ret = longestConsecutive(root->right);
        //     mx = max(mx, ret + (root->right->val == root->val + 1 ? 1 : 0));
        // }

        // return mx;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif