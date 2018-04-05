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
class Solution
{
private:
    // path sum, not subtree sum!!
    // watch out for the values to take!
    int dfs(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return INT_MIN;

        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);

        // at least return self, case [-3]
        int path =
            root->val + max((l >= 0 ? l : 0), (r >= 0 ? r : 0)); // to be returned
        ans = max(ans, path);

        // path rooted at this point
        int rooted =
            root->val + (l >= 0 ? l : 0) + (r >= 0 ? r : 0); // to be returned
        ans = max(ans, rooted);

        // self only
        ans = max(ans, root->val);

        return path;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        if (root == NULL)
            return ans;

        dfs(root, ans);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif