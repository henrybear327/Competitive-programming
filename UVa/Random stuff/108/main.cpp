#include <bits/stdc++.h>

using namespace std;

int main()
{		
	int n;
	while(scanf("%d", &n) == 1) {
		// read input
		int data[n + 1][n + 1];
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= n; j++) 
				scanf("%d", &data[i][j]);
		
		// compute column prefix sum
		int pre[n + 1][n + 1];
		memset(pre, 0, sizeof(pre));
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= n; j++) 
				pre[i][j] = pre[i - 1][j] + data[i][j];

		// i, j is row
		int ans = INT_MIN;
		for(int i = 0; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				// row (i, j]
				int sum = 0;
				// k is doing max sub array, on rectangle
				for(int k = 1; k <= n; k++) {
					sum += pre[j][k] - pre[i][k];
					if(sum < 0)
						sum = 0;
					ans = max(sum, ans);
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
