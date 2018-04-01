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
    void dfs(TreeNode *root, unordered_map<TreeNode *, vector<TreeNode *>> &lca,
             int d, unordered_map<TreeNode *, int> &depth)
    {
        if (root == NULL)
            return;

        depth[root] = d;
        if (root->left) {
            lca[root->left].push_back(root);
            dfs(root->left, lca, d + 1, depth);
        }
        if (root->right) {
            lca[root->right].push_back(root);
            dfs(root->right, lca, d + 1, depth);
        }
    }

    TreeNode *getParAtLevel(unordered_map<TreeNode *, vector<TreeNode *>> &lca,
                            TreeNode *node, int level)
    {
        if (level < (int)lca[node].size())
            return lca[node][level];
        return NULL;
    }

    void build(unordered_map<TreeNode *, vector<TreeNode *>> &lca)
    {
        // for (auto i : lca) {
        //     printf("%d: ", i.first->val);
        //     for (auto j : i.second) {
        //         printf("%d ", j->val);
        //     }
        //     printf("\n");
        // }
        // puts("===");

        for (int level = 0;; level++) { // building level + 1
            int cnt = 0;
            for (auto i : lca) {
                TreeNode *nxt = getParAtLevel(lca, i.first, level);
                if (nxt != NULL) {
                    TreeNode *target = getParAtLevel(lca, nxt, level);
                    if (target != NULL) {
                        lca[i.first].push_back(target);
                        cnt++;
                    }
                }
            }
            if (cnt == 0)
                break;
        }

        // for (auto i : lca) {
        //     printf("%d: ", i.first->val);
        //     for (auto j : i.second) {
        //         printf("%d ", j->val);
        //     }
        //     puts("");
        // }
    }

    TreeNode *go(unordered_map<TreeNode *, vector<TreeNode *>> &lca,
                 unordered_map<TreeNode *, int> &depth, TreeNode *p,
                 TreeNode *q)
    {
        // for (auto i : depth)
        //     printf("%d -> %d\n", i.first->val, i.second);
        // puts("===");

        // move to same level
        if (depth[p] < depth[q])
            swap(p, q);
        // printf("in dp %d -> %d dq %d -> %d\n", p->val, depth[p], q->val,
        // depth[q]);
        int diff = depth[p] - depth[q];
        if (diff > 0) {
            for (int i = 0; diff > 0; i++, diff >>= 1) {
                if (diff & 1) {
                    p = lca[p][i];
                }
            }
        }
        if (p == q)
            return p;
        // printf("dp %d dq %d\n", depth[p], depth[q]);

        // x v v v v v v
        // find rightmost x
        for (int step = 10; step >= 0; step--) {
            TreeNode *adv_p = getParAtLevel(lca, p, step);
            TreeNode *adv_q = getParAtLevel(lca, q, step);
            // printf("%d %d\n", !adv_p ? -1 : adv_p->val, !adv_q ? -1 : adv_q->val);
            if (adv_p != NULL && adv_q != NULL && adv_p != adv_q) { // x
                p = adv_p;
                q = adv_q;
            }
        }

        // advance by 1 (special case: root)
        TreeNode *adv_p = getParAtLevel(lca, p, 0);
        if (adv_p != NULL) {
            p = adv_p;
        }
        // printf("LCA = %d\n", p->val);
        return p;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_map<TreeNode *, vector<TreeNode *>> lca;
        unordered_map<TreeNode *, int> depth;
        dfs(root, lca, 0, depth);

        build(lca);

        return go(lca, depth, p, q);
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

TreeNode *stringToTreeNode(string input, int m_val, TreeNode *&m, int n_val,
                           TreeNode *&n)
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

        if (node->val == m_val)
            m = node;
        if (node->val == n_val)
            n = node;

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
            if (node->left->val == m_val)
                m = node->left;
            if (node->left->val == n_val)
                n = node->left;
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
            if (node->right->val == m_val)
                m = node->right;
            if (node->right->val == n_val)
                n = node->right;
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

int stringToInteger(string input)
{
    return stoi(input);
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
    string treeLine, line;
    while (getline(cin, treeLine)) {
        getline(cin, line);
        int m_val = stringToInteger(line);
        getline(cin, line);
        int n_val = stringToInteger(line);
        TreeNode *m, *n;
        TreeNode *root = stringToTreeNode(treeLine, m_val, m, n_val, n);

        TreeNode *ret = Solution().lowestCommonAncestor(root, m, n);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
#endif