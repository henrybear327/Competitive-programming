// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...
#include <bits/stdc++.h>
using namespace std;

static int initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    int depth = 1;
    int pre[1111] = {0};

public:
    int pathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;

        // get prefix sum
        pre[depth] = root->val;
        pre[depth] += pre[depth - 1];

        // do sum check (ending at current element)
        int ret = 0;
        for (int i = 0; i < depth; i++)
            if (pre[depth] - pre[i] == sum)
                ret++;

        depth++;
        ret += pathSum(root->left, sum);
        ret += pathSum(root->right, sum);
        depth--;

        return ret;
    }
};

int main()
{
    return 0;
}