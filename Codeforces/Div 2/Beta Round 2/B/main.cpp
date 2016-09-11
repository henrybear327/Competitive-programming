#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define RIGHT 1
#define DOWN 2

ii operator+(ii a, ii b)
{
	return ii(a.first + b.first, a.second + b.second);
}

int main()
{
	int n;
	scanf("%d", &n);

	ii inp[n][n];
	int zx = -1, zy = -1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			ll tmp;
			scanf("%lld", &tmp);
			
			if(tmp == 0) { // 0 pos
				zx = i;
				zy = j;
			} else {
				// decompose number
				while(tmp % 2 == 0) {
					tmp /= 2;
					inp[i][j].first++;
				}
				while(tmp % 5 == 0) {
					tmp /= 5;
					inp[i][j].second++;
				}
			}
		}
	
	// DP
	// base case
	ii dp[n][n], dir[n][n];
	dp[0][0] = inp[0][0];
	for(int j = 1; j < n; j++) {
		dp[0][j].first = dp[0][j - 1].first + inp[0][j].first;
		dp[0][j].second = dp[0][j - 1].second + inp[0][j].second;
		dir[0][j].first = dir[0][j].second = RIGHT;
	}

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < n; j++) {
			// from top
			dp[i][j].first = dp[i - 1][j].first + inp[i][j].first;
			dp[i][j].second = dp[i - 1][j].second + inp[i][j].second;
			dir[i][j].first = dir[i][j].second = DOWN;

			// from left
			if(j > 0) {
				int res1 = dp[i][j - 1].first + inp[i][j].first;
				int res2 = dp[i][j - 1].second + inp[i][j].second;
				if(dp[i][j].first > res1) {
					dp[i][j].first = res1;
					dir[i][j].first = RIGHT;
				}
				if(dp[i][j].second > res2) {
					dp[i][j].second = res2;
					dir[i][j].second = RIGHT;
				}
			}
		}
	}

	int ans = min(dp[n - 1][n - 1].first, dp[n - 1][n - 1].second);
	if(zx != -1 && ans != 0) {
		// make a route that passes 0
		int d1 = zx;
		int r1 = zy;
		int d2 = n - 1 - zx;
		int r2 = n - 1 - zy;

		printf("1\n");
		for(int i = 0; i < d1; i++)
			printf("D");
		for(int i = 0; i < r1; i++)
			printf("R");
		for(int i = 0; i < d2; i++)
			printf("D");
		for(int i = 0; i < r2; i++)
			printf("R");
	} else {
		// trace route
		stack<int> s;
		if(dp[n - 1][n - 1].first < dp[n - 1][n - 1].second) {
			// trace by first
			int x = n - 1, y = n - 1;
			while(x != 0 || y != 0) {
				s.push(dir[x][y].first);
				if(dir[x][y].first == RIGHT)
					y--;
				else
					x--;
			}
		} else {
			// trace by second
			int x = n - 1, y = n - 1;
			while(x != 0 || y != 0) {
				s.push(dir[x][y].second);
				if(dir[x][y].second == RIGHT)
					y--;
				else
					x--;
			}
		}

		printf("%d\n", ans);
		while(s.empty() == false) {
			printf("%c", s.top() == RIGHT ? 'R' : 'D');
			s.pop();
		}
	}

	return 0;
}
