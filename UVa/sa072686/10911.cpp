#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const double oo = 1e9;

double dist[22][22];

void dfs(int s, double dp[], int n)
{
	if (dp[s] != oo)
		return;
	// 1 means not paired uet
	for (int i = 0; i < n; i++) {
		if ((s >> i) & 1) {
			for (int j = i + 1; j < n; j++) {
				if (i == j) // pair with self, cont.
					continue;
				if ((s >> j) & 1) {
					int nxt = s ^ (1 << i) ^ (1 << j);
					dfs(nxt, dp, n);
					dp[s] = min(dp[s], dp[nxt] + dist[i][j]);
				}
			}
		}
	}
}

double solve(int n)
{
	n *= 2;
	ii pos[n];
	for (int i = 0; i < n; i++) {
		char inp[111];
		scanf("%s %d %d", inp, &pos[i].first, &pos[i].second);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int dx = pos[i].first - pos[j].first;
			int dy = pos[i].second - pos[j].second;
			dist[i][j] = sqrt(dx * dx + dy * dy);
		}
	}

	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < n; j++) {
	// 		printf("%7.2f%c", dist[i][j], j == n - 1 ? '\n' : ' ');
	// 	}

	double dp[1 << n];
	fill(dp, dp + (1 << n), oo);
	dp[0] = 0; // base case
	dfs((1 << n) - 1, dp, n);
	return dp[(1 << n) - 1];
}

int main()
{
	int n;
	for (int i = 1; scanf("%d", &n) == 1 && n; i++) {
		printf("Case %d: %.2f\n", i, solve(n));
	}

	return 0;
}
