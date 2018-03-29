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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        vector<int> level;
        level.push_back(root->val);
        ans.push_back(level);

        while (q.size() > 0) {
            int level_size = q.size();
            level.clear();

            for (int i = 0; i < level_size; i++) {
                TreeNode *cur = q.front();
                q.pop();

                if (cur->left) {
                    q.push(cur->left);
                    level.push_back(cur->left->val);
                }
                if (cur->right) {
                    q.push(cur->right);
                    level.push_back(cur->right->val);
                }
            }

            if(level.size() > 0)
                ans.push_back(level);
        }

        return ans;
    }
};

// class Solution
// {
// public:
//     vector<vector<int>> levelOrder(TreeNode *root)
//     {
//         queue<TreeNode *> q;
//         vector<vector<int>> ans;
//         unordered_map<TreeNode *, pair<int, int>> level;

//         if (root == NULL)
//             return ans;

//         q.push(root);
//         level[root] = make_pair(0, 0);
//         int mx = 0;
//         int timer = 1;
//         while (q.size() > 0) {
//             TreeNode *cur = q.front();
//             q.pop();

//             if (cur->left) {
//                 level[cur->left] =
//                     make_pair(level[cur].first + 1, timer++); // level,
//                     timestamp
//                 mx = max(mx, level[cur->left].first);
//                 q.push(cur->left);
//             }
//             if (cur->right) {
//                 level[cur->right] = make_pair(level[cur].first + 1, timer++);
//                 mx = max(mx, level[cur->right].first);
//                 q.push(cur->right);
//             }
//         }

//         for (int i = 0; i <= mx; i++) {
//             vector<int> tmp;
//             ans.push_back(tmp);
//         }

//         map<pair<int, int>, int> levelOrder;
//         for (auto i : level) {
//             levelOrder[i.second] = i.first->val;
//         }

//         for (auto i : levelOrder) {
//             ans[i.first.first].push_back(i.second);
//         }

//         return ans;
//     }
// };

int main()
{
    return 0;
}