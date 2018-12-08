// :%s/^ \* //g
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
public:
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);

        while (q.size() >= 2) {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();

            if (left == NULL && right == NULL)
                continue;
            if (left == NULL || right == NULL)
                return false;
            if (left->val != right->val)
                return false;

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
