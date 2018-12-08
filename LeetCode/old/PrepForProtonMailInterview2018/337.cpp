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

typedef pair<int, int> ii;

class Solution
{
private:
    ii dfs(TreeNode *root)
    {
        if (root == NULL) {
            return ii(0, 0);
        }

        ii left = dfs(root->left);
        ii right = dfs(root->right);

        ii ans;
        ans.first = root->val + left.second + right.second;
        ans.second = max(left.first, left.second) + max(right.first, right.second);

        return ans;
    }

public:
    int rob(TreeNode *root)
    {
        ii ret = dfs(root);
        return max(ret.first, ret.second);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
