// :%s/^ \* //g
#ifdef LOCAL
#include <iostream>
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
    TreeNode *res = NULL;
    TreeNode *cur = NULL;

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        increasingBST(root->left);
        if (res == NULL)
            res = cur = new TreeNode(root->val);
        else {
            cur->right = new TreeNode(root->val);
            cur = cur->right;
        }
        increasingBST(root->right);

        return res;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
