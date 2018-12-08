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
    TreeNode *prev;
    void traverse(TreeNode *root)
    {
        if (root == nullptr)
            return;
        traverse(root->right);
        traverse(root->left);

        if (prev != nullptr) {
            root->right = prev;
            root->left = nullptr;
        }
        prev = root;
    }

public:
    void flatten(TreeNode *root)
    {
        prev = nullptr;
        traverse(root);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif