// What a problem!!
// Create a super node and think of a mirror! There you go!

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
    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }

private:
    bool check(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        if (left->val != right->val)
            return false;

        return check(left->right, right->left) && check(left->left, right->right);
    }
};

// What a solution
// public boolean isSymmetric(TreeNode root) {
//     Queue<TreeNode> q = new LinkedList<>();
//     q.add(root);
//     q.add(root);
//     while (!q.isEmpty()) {
//         TreeNode t1 = q.poll();
//         TreeNode t2 = q.poll();
//         if (t1 == null && t2 == null) continue;
//         if (t1 == null || t2 == null) return false;
//         if (t1.val != t2.val) return false;
//         
//         // WOW
//         q.add(t1.left);
//         q.add(t2.right);
//         q.add(t1.right);
//         q.add(t2.left);
//     }
//     return true;
// }

int main()
{
    return 0;
}
