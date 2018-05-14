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

// handle special cases first
// [], "", ...
// range of input?
class Solution
{
private:
	TreeNode *ans;
	void dfs(TreeNode *root, int &k)
	{
		if (root == NULL)
			return;
		dfs(root->left, k);
		k--;
		if (k == 0)
			ans = root;
		dfs(root->right, k);
	}

public:
	int kthSmallest(TreeNode *root, int k)
	{
		ans = NULL;
		dfs(root, k);

		return ans->val;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif