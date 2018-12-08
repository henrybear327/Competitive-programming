#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
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
	const int dx[4] = {0, 0, 1, -1};
	const int dy[4] = {1, -1, 0, 0};

	vector<vector<int>> *mat;

	vector<vector<int>> dp[2];
	int n, m;
	bool in(int x, int y)
	{
		return (0 <= x && x < n) && (0 <= y && y < m);
	}
	void dfs(int x, int y, int type)
	{
		if (dp[type][x][y] != 0)
			return;
		dp[type][x][y] = 1;

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (in(xx, yy) && (*mat)[xx][yy] >= (*mat)[x][y]) {
				dfs(xx, yy, type);
			}
		}
	}

public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix)
	{
		vector<pair<int, int>> ans;
		n = matrix.size();
		if (n == 0)
			return ans;
		m = matrix[0].size();
		if (m == 0)
			return ans;
		mat = &matrix;

		dp[0] = vector<vector<int>>(n, vector<int>(m, 0));
		dp[1] = vector<vector<int>>(n, vector<int>(m, 0));

		for (int i = 0; i < n; i++) {
			dfs(i, 0, 0);
			dfs(i, m - 1, 1);
		}

		for (int i = 0; i < m; i++) {
			dfs(0, i, 0);
			dfs(n - 1, i, 1);
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (dp[0][i][j] + dp[1][i][j] == 2)
					ans.push_back(pair<int, int>(i, j));

		return ans;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif