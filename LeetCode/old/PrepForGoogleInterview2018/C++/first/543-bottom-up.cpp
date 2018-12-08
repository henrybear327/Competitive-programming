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
    unordered_map<TreeNode *, vector<TreeNode *>>
            g; // only use par will WA (skew tree)
    unordered_map<TreeNode *, int> deg;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;

        if (root->left != NULL) {
            g[root->left].push_back(root);
            g[root].push_back(root->left);

            deg[root]++;
            deg[root->left]++;
        }
        if (root->right != NULL) {
            g[root->right].push_back(root);
            g[root].push_back(root->right);

            deg[root]++;
            deg[root->right]++;
        }

        dfs(root->left);
        dfs(root->right);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        queue<TreeNode *> q;
        unordered_map<TreeNode *, int> depth;
        for (auto i : deg) {
            cerr << "deg: " << i.second << " node: " << i.first->val << endl;
            if (i.second == 1) {
                q.push(i.first);
                depth[i.first] = 0;
            }
        }

        int mx = 0;
        while (q.size() > 0) {
            auto cur = q.front();
            cerr << "pop: " << cur->val << endl;
            q.pop();

            for (auto v : g[cur]) {
                deg[v]--;
                if (deg[v] == 1) {
                    depth[v] = depth[cur] + 1;
                    mx = max(depth[v], mx);
                    cerr << "push: " << v->val << endl;
                    q.push(v);
                }
            }
        }

        cerr << "mx: " << mx << endl;

        int cnt = 0;
        for (auto i : depth) {
            cerr << "dep: " << i.second << " who: " << i.first->val << endl;
            if (i.second == mx)
                cnt++;
        }

        cerr << "cnt: " << cnt << endl;

        if (cnt == 0) // WA
            return 0;
        return cnt == 1 ? mx * 2 : mx * 2 + 1;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(),
    [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(
    find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    })
    .base(),
    input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);

        int ret = Solution().diameterOfBinaryTree(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}