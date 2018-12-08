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
const double oo = 1e9;
class Solution
{
public:
	vector<double> calcEquation(vector<pair<string, string>> equations,
	                            vector<double> &values,
	                            vector<pair<string, string>> queries)
	{
		unordered_map<string, int> cnt;
		int idx = 0;
		for (auto equation : equations) {
			if (cnt.count(equation.first) == 0)
				cnt[equation.first] = idx++;
			if (cnt.count(equation.second) == 0)
				cnt[equation.second] = idx++;
		}

		double g[idx][idx];
		for (int i = 0; i < idx; i++)
			for (int j = 0; j < idx; j++)
				if (i == j)
					g[i][j] = 1;
				else
					g[i][j] = oo;

		for (int i = 0; i < (int)equations.size(); i++) {
			int u = cnt[equations[i].first];
			int v = cnt[equations[i].second];
			// printf("%d %d\n", u, v);
			g[u][v] = values[i];
			g[v][u] = values[i] == 0 ? 0 : 1 / values[i];
		}

		// for (int i = 0; i < idx; i++)
		// 	for (int j = 0; j < idx; j++)
		// 		printf("%16.2f%c", g[i][j], j == idx - 1 ? '\n' : ' ');

		for (int k = 0; k < idx; k++)
			for (int i = 0; i < idx; i++)
				for (int j = 0; j < idx; j++)
					if (g[i][k] == oo || g[k][j] == oo)
						continue;
					else
						g[i][j] = min(g[i][j], g[i][k] * g[k][j]);

		// for (int i = 0; i < idx; i++)
		// 	for (int j = 0; j < idx; j++)
		// 		printf("%16.2f%c", g[i][j], j == idx - 1 ? '\n' : ' ');

		vector<double> ans;
		for (auto query : queries) {
			if (cnt.count(query.first) == 0) {
				ans.push_back(-1);
				continue;
			}
			int u = cnt[query.first];
			if (cnt.count(query.second) == 0) {
				ans.push_back(-1);
				continue;
			}
			int v = cnt[query.second];

			if (g[u][v] == oo)
				ans.push_back(-1);
			else
				ans.push_back(g[u][v]);
		}

		return ans;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif