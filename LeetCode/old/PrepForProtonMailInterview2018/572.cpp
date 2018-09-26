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
private:
    bool check(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;
        if (s != NULL && t != NULL && s->val == t->val)
            return check(s->left, t->left) && check(s->right, t->right);
        return false;
    }

public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;

        if (check(s, t))
            return true;
        // s and t ptr check!
        return (s != NULL && t != NULL) &&
               (isSubtree(s->left, t) || isSubtree(s->right, t));
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
