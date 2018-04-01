#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

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
    void dfs(TreeNode *root, unordered_map<int, vector<int>> &lca)
    {
        if (root == NULL)
            return;

        if (root->left) {
            lca[root->left->val].push_back(root->val);
            dfs(root->left, lca);
        }
        if (root->right) {
            lca[root->right->val].push_back(root->val);
            dfs(root->right, lca);
        }
    }

    void build(unordered_map<int, vector<int>> &lca)
    {
        printf("IN\n");
        for (auto i : lca) {
            printf("%d: ", i.first);
            for (auto j : i.second) {
                printf("%d ", j);
            }
            puts("\n===");
        }

        for (int level = 0;; level++) { // building level + 1
            int cnt = 0;
            for (auto i : lca) {
                printf("i = %d\n", i.first);

                if (level < (int)lca[i.first].size()) {
                    int nxt = lca[i.first][level];

                    if (level < (int)lca[nxt].size()) {
                        int target = lca[nxt][level];
                        lca[i.first].push_back(target);
                        cnt++;
                    }
                }
            }
            if (cnt == 0)
                break;
        }

        for (auto i : lca) {
            printf("%d: ", i.first);
            for (auto j : i.second) {
                printf("%d ", j);
            }
            puts("");
        }
        printf("Out");
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_map<int, vector<int>> lca;
        dfs(root, lca);

        build(lca);

        return NULL;
    }
};

#ifdef LOCAL

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

TreeNode *findNode(TreeNode *root, int node)
{
    if (!root)
        return NULL;
    if (root->val == node)
        return root;
    TreeNode *l = findNode(root->left, node);
    TreeNode *r = findNode(root->right, node);
    if (l != NULL)
        return l;
    return r;
}

TreeNode *stringToInteger(string input, TreeNode *root)
{
    int node = stoi(input);
    return findNode(root, node);
}

string treeNodeToString(TreeNode *root)
{
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);
        getline(cin, line);
        TreeNode *m = stringToInteger(line, root);
        getline(cin, line);
        TreeNode *n = stringToInteger(line, root);

        TreeNode *ret = Solution().lowestCommonAncestor(root, m, n);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
#endif