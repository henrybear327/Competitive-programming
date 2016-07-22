#include <bits/stdc++.h>

using namespace std;

#define MAX_N 20
int dp[MAX_N][1111], t[MAX_N], w[MAX_N], v[MAX_N];

int main()
{
    int n, m, c0, d0;
    scanf("%d %d %d %d", &n, &m, &c0, &d0);
    
    memset(dp, 0, sizeof(dp));
    t[m + 1] = n / c0;
    w[m + 1] = c0;
    v[m + 1] = d0;
    for(int i = 1; i <= m; i++) {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	t[i] = a / b;
	w[i] = c;
	v[i] = d;
    }

    for(int i = 1; i <= m + 1; i++) {
	for(int j = 1; j <= n; j++) {
	    for(int k = 0; k <= t[i] && j - w[i] * k >= 0; k++) {
		dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i] * k] + v[i] * k);
	    }
	}
    }

    printf("%d\n", dp[m + 1][n]);
    
    return 0;
}
