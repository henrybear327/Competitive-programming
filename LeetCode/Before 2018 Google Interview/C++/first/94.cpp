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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *cur = root;

        while (s.size() > 0 || cur != NULL) {
            if (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            } else {
                if (s.size() > 0) {
                    cur = s.top();
                    s.pop();

                    ans.push_back(cur->val);

                    cur = cur->right;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}