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
    void dfs(TreeNode *root, TreeNode *p, int acc, int &ans)
    {
        if (root == NULL)
            return;
        if (p != NULL && p->val + 1 == root->val) {
            acc++;
        } else {
            acc = 1;
        }

        ans = max(ans, acc);
        dfs(root->left, root, acc, ans);
        dfs(root->right, root, acc, ans);
    }

public:
    int longestConsecutive(TreeNode *root)
    {
        int ans = 0;
        dfs(root, NULL, 1, ans);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif