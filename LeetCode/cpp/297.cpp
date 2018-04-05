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

static int __initialSetup =
    []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

();

// handle special cases first
// [], "", ...

class Codec
{
private:
    void encode(TreeNode *root, string &ans)
    {
        if (root) {
            ans += (ans.size() == 0 ? "" : ",") + to_string(root->val);
            encode(root->left, ans);
            encode(root->right, ans);
        } else {
            ans += ",#";
        }
    }

    TreeNode *decode(stringstream &ss)
    {
        string token;
        if (getline(ss, token, ',')) {
            // cout << token << endl;
            if (token == "#") {
                return NULL;
            } else {
                int val = stoi(token);
                TreeNode *nxt = new TreeNode(val);
                nxt->left = decode(ss);
                nxt->right = decode(ss);
                return nxt;
            }
        } else {
            return NULL;
        }
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans;
        if (root == NULL)
            return ans;

        encode(root, ans);
        // cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss;
        ss.str(data);
        return decode(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#ifdef LOCAL
int main()
{
    return 0;
}
#endif