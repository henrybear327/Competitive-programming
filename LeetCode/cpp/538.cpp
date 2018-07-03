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
    int sum = 0;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        TreeNode *newNode = new TreeNode(root->val);

        newNode->right = convertBST(root->right);
        int orig = root->val; // cricual!
        newNode->val += sum;
        sum += orig;
        newNode->left = convertBST(root->left);

        return newNode;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
