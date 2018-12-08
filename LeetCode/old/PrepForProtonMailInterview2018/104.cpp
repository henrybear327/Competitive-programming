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
    void dfs(TreeNode *root, int depth, int &mx)
    {
        if (root == NULL)
            return;
        mx = max(mx, depth);
        dfs(root->left, depth + 1, mx);
        dfs(root->right, depth + 1, mx);
    }

public:
    int maxDepth(TreeNode *root)
    {
        int mx = 0;
        dfs(root, 1, mx);
        return mx;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
