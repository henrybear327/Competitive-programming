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
    void dfs(TreeNode *root, int &ans, int acc, multiset<int> &pre,
             int &sum) // prefix sum is not non-decreasing
    {
        if (root == NULL)
            return;

        acc += root->val;

        int target = acc - sum;
        ans += pre.count(target);

        /*
        case
        [1]
        0
        */
        pre.insert(acc); // do cal then insert

        dfs(root->left, ans, acc, pre, sum);
        dfs(root->right, ans, acc, pre, sum);

        auto it = pre.find(acc);
        if (it != pre.end())
            pre.erase(it);
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        int ans = 0;
        multiset<int> pre;
        pre.insert(0);
        dfs(root, ans, 0, pre, sum);
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif
