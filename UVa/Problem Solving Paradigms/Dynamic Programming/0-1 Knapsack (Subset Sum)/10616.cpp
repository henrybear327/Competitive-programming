#include <bits/stdc++.h>

using namespace std;

int val[22];
int dp[222][11][22];

void build(int n, int d) // consider d when building table!!!!
{
	memset(dp, 0, sizeof(dp));
	
	dp[0][0][0] = 1; // base case 
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 10; j++) { // starting from 0 for easy processing
			for(int k = 0; k < d; k++) { // although the range is 1 ~ d, we can use 1, 2, 3, ...., d - 1, 0 for mod to work 
				// DP
				// dp[when picking up till number i][used j values][value k after mod d]
				// dp[i][j][k] = dp[i - 1 up till considering previous number][used j values -> current val not used][value k after mod d] +
				// 				 dp[i - 1 up till considering previous number][used j - 1 values -> current val used][value k after mod d]
				dp[i][j][k] = dp[i - 1][j][k]; 

				if(j > 0) {
					int x = (k - val[i] % d + d) % d; // val[i] % d trick!
					dp[i][j][k] += dp[i - 1][j - 1][x];	
				}
			}
		}
	}
	
	/*
	for(int i = 1; i <= n; i++) {
		printf("i = %d, %d\n", i, val[i]);
		
		for(int j = 0; j <= 10; j++) {
			for(int k = 0; k <= 20; k++) {
				printf("%3d", dp[i][j][k]);
			}
			printf("\n");
		}
	}
	*/
}

void solve(int n, int q, int ncase)
{
	printf("SET %d:\n", ncase);

	for(int i = 1; i <= q; i++) {
		int d, m;
		scanf("%d %d", &d, &m);
		build(n, d);
		printf("QUERY %d: %d\n", i, dp[n][m][0]); // just get the [0] since 1~d maps to 1, 2, ..., d - 1, 0
	}
}	

int main()
{
	int n, q;
	int ncase = 1;
	while(scanf("%d %d", &n, &q) == 2 && (n || q)) {
		for(int i = 1; i <= n; i++)
			scanf("%d", &val[i]);

		solve(n, q, ncase);
		ncase++;
	}

	return 0;
}
