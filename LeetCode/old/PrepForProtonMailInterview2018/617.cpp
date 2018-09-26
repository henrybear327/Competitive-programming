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

// Iterative
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {}
};

// recursion
class SolutionRecursion
{
private:
    TreeNode *dfs(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == NULL && t2 == NULL)
            return NULL;
        int val = 0;
        if (t1 != NULL) {
            val += t1->val;
        }

        if (t2 != NULL) {
            val += t2->val;
        }

        TreeNode *newNode = new TreeNode(val);
        newNode->left = dfs(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
        newNode->right = dfs(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
        return newNode;
    }

public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        return dfs(t1, t2);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
