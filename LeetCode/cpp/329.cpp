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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

// [[3,4,5],[3,2,6],[2,2,1]]
class Solution
{
private:
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};

	bool in(int n, int m, int x, int y)
	{
		return (0 <= x && x < n) && (0 <= y && y < m);
	}

public:
	int longestIncreasingPath(vector<vector<int>> &matrix)
	{
		int n = matrix.size();
		if (n == 0)
			return 0;
		int m = matrix[0].size();
		if (m == 0)
			return 0;

		vector<vector<int>> in_deg(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
					int xx = i + dx[k];
					int yy = j + dy[k];

					if (in(n, m, xx, yy) && matrix[xx][yy] > matrix[i][j])
						in_deg[xx][yy]++;
				}
			}

		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) {
		// 		cout << in_deg[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		queue<ii> q;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (in_deg[i][j] == 0)
					q.push(ii(i, j));

		int ans = 1, sz = q.size();
		// cout << sz << endl;
		while (q.size() > 0) {
			auto cur = q.front();
			q.pop();
			// cout << "out " << matrix[cur.first][cur.second] << " " << cur.first <<
			// " "
			//      << cur.second << " " << sz << endl;

			sz--;

			int x = cur.first;
			int y = cur.second;

			for (int j = 0; j < 4; j++) {
				int xx = x + dx[j];
				int yy = y + dy[j];

				if (in(n, m, xx, yy) && matrix[xx][yy] > matrix[x][y]) {
					in_deg[xx][yy]--;
					if (in_deg[xx][yy] == 0) {
						// cout << "push " << xx << " " << yy << endl;
						q.push(ii(xx, yy));
					}
				}
			}

			// for (int i = 0; i < n; i++) {
			// 	for (int j = 0; j < m; j++) {
			// 		cout << in_deg[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }

			if (sz == 0) { // you must do updating here! Or you will miss the nodes
				// being pushed in by the sz = 1 node
				sz = q.size();
				if(sz > 0)
					ans++;
				// cout << "sz " << sz << endl;
			}
		}
		// cout << "fucked" << endl;
		return ans;
	}

	// int longestIncreasingPath(vector<vector<int>> &matrix)
	// {
	// 	int n = matrix.size();
	// 	if (n == 0)
	// 		return 0;
	// 	int m = matrix[0].size();
	// 	if (m == 0)
	// 		return 0;

	// 	vector<vector<int>> dp(n, vector<int>(m, 1));

	// 	vector<iii> inp;
	// 	for (int i = 0; i < n; i++)
	// 		for (int j = 0; j < m; j++) {
	// 			inp.push_back(iii(matrix[i][j], ii(i, j)));
	// 		}
	// 	sort(inp.begin(), inp.end());

	// 	for (auto i : inp) {
	// 		int x = i.second.first;
	// 		int y = i.second.second;

	// 		for (int j = 0; j < 4; j++) {
	// 			int xx = x + dx[j];
	// 			int yy = y + dy[j];

	// 			if (in(n, m, xx, yy) && matrix[xx][yy] > matrix[x][y])
	// 				dp[xx][yy] = max(dp[xx][yy], dp[x][y] + 1);
	// 		}
	// 	}

	// 	int ans = 0;
	// 	for (int i = 0; i < n; i++)
	// 		for (int j = 0; j < m; j++)
	// 			ans = max(dp[i][j], ans);
	// 	return ans;
	// }
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif