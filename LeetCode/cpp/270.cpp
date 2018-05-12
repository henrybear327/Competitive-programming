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
    double diff = LLONG_MAX;
    int val;
    void dfs(TreeNode *root, const double &target)
    {
        if (root == NULL)
            return;
        if (fabs(1.0 * root->val - target) < diff) {
            diff = fabs(1.0 * root->val - target);
            val = root->val;
        }

        dfs(root->left, target);
        dfs(root->right, target);
    }

public:
    int closestValue(TreeNode *root, double target)
    {
        dfs(root, target);

        return val;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif