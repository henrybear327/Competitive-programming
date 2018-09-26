// :%s/^ \*//g
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
    int ans = 0;

    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        ans = max(ans, left + right);

        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
