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
public:
    bool isEqual(TreeNode *s, TreeNode *t) {
        if(s == NULL && t == NULL)
            return true;
        else if(s == NULL || t == NULL)
            return false;
        else 
            return isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if(s == NULL || t == NULL)
            return false;
            
        if(s->val == t->val)
            return isEqual(s, t);
        else {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};

int main()
{
    return 0;
}
