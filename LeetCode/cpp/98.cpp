// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

static int __initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
private:
    bool dfs(TreeNode *root, long long int l, long long int r)
    {
        if (root == NULL)
            return true;

        if (l <= root->val && root->val <= r) {
            bool rl = dfs(root->left, l, (long long int)root->val - 1);
            bool rr = dfs(root->right, (long long int)root->val + 1, r);
            return rl == true && rr == true;
        }
        return false;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif