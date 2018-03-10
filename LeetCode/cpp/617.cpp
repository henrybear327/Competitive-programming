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
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == NULL && t2 == NULL)
            return NULL;

        // get current node value
        int val = (t1 == NULL ? 0 : t1->val) + (t2 == NULL ? 0 : t2->val);
        TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
        newNode->val = val;
        newNode->left = newNode->right = NULL;

        // get link
        newNode->left =
            mergeTrees((t1 == NULL ? 0 : t1->left), (t2 == NULL ? 0 : t2->left));
        newNode->right =
            mergeTrees((t1 == NULL ? 0 : t1->right), (t2 == NULL ? 0 : t2->right));
        return newNode;
    }
};

int main()
{
    return 0;
}