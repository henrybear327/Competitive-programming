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
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

class BSTIterator
{
private:
    TreeNode *root;
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *_root)
    {
        root = _root;

        for (TreeNode *cur = _root; cur != NULL; cur = cur->left)
            st.push(cur);

        // cout << st.size() << endl;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return st.size() > 0;
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *ans = st.top();
        st.pop(); // pop self! This is crucial!

        for (TreeNode *cur = ans->right; cur != NULL; cur = cur->left) {
            st.push(cur);
        }

        return ans->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

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

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);

        BSTIterator it(root);
        vector<int> ret;
        while (it.hasNext())
            ret.push_back(it.next());

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
#endif