#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

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
typedef pair<int, int> ii;
class Solution
{
private:
    int ans;
    ii dfs(TreeNode *root) // inc, dec
    {
        if (root == NULL)
            return ii(0, 0);

        ii l = dfs(root->left);
        ii r = dfs(root->right);

        if (root->left != NULL) {
            if (root->left->val + 1 == root->val)
                l.first++;
            else
                l.first = 0;

            if (root->left->val - 1 == root->val)
                l.second++;
            else
                l.second = 0;
        }

        if (root->right != NULL) {
            if (root->right->val + 1 == root->val)
                r.first++;
            else
                r.first = 0;

            if (root->right->val - 1 == root->val)
                r.second++;
            else
                r.second = 0;
        }

        // cout << (root->left ? root->left->val : -1) << " " << root->val << " "
        //      << (root->right ? root->right->val : -1) << endl;
        // cout << l.first << " " << l.second << endl;
        // cout << r.first << " " << r.second << endl;

        ans = max(ans, max(l.first, l.second));
        ans = max(ans, max(r.first, r.second));
        ans = max(ans, max(l.first + r.second, l.second + r.first));

        return ii(max(l.first, r.first), max(l.second, r.second));
    }

public:
    int longestConsecutive(TreeNode *root)
    {
        ans = 0;
        dfs(root);
        return root ? ans + 1 : 0;
    }
};
#ifdef LOCAL
int main()
{
    return 0;
}
#endif