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

class Solution
{
public:
    // only return not NULL value when root == p or root == q
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root == p || root == q) // matched, return
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL && right != NULL) // p, q not in left subtree
            return right;
        else if (left == NULL && right == NULL)
            return NULL;
        else if (left != NULL && right == NULL) // p, q not in right subtree
            return left;
        else // ahh! left has one match, right has one match -> this node is lca
            return root;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif