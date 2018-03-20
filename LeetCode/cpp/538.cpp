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
    int sum = 0;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        convertBST(root->right);
        // int orig = root->val;
        // root->val += sum;
        // sum += orig;

        root->val += sum;
        sum = root->val;
        convertBST(root->left);
    }
};

int main()
{
    return 0;
}