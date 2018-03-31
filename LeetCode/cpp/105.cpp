// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
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

// observations
// preorder: it's like taking you through the roots of the tree
// inorder: it's like telling you who's on the left subtree
// and who's on the right one
class Solution
{
private:
    // [l, r)
    TreeNode *go(vector<int> &preorder, unordered_map<int, int>& lookup, int &pi,
                 int l, int r)
    {
        // terminating condition
        if (l == r) {
            pi--;
            return NULL;
        }
        // printf("pre = %d (%d), l %d r %d\n", preorder[pi], pi, l, r);

        // create new node (preorder[pi] is the current root)
        TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
        newNode->left = newNode->right = NULL;
        newNode->val = preorder[pi];

        int i = lookup[preorder[pi]];
        // recurse
        pi++;
        newNode->left = go(preorder, lookup, pi, l, i);
        pi++;
        newNode->right = go(preorder, lookup, pi, i + 1, r);

        return newNode;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = NULL;
        unordered_map<int, int> lookup;
        for (int i = 0; i < (int)inorder.size(); i++) {
            lookup[inorder[i]] = i;
        }

        if (preorder.size() > 0) {
            int pi = 0;
            root = go(preorder, lookup, pi, 0, preorder.size());
        }

        return root;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif