#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int dp[1000100];

void build()
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;

	for (long long i = 2; i <= 1000000; i++) {
		// printf("i = %d\n", i);
		if (dp[i] == 0) {
			dp[i] = 1;
			for (long long j = i * 2; j <= 1000000; j += i) {
				dp[j]++;
			}
		}
	}
}

int main()
{
	build();
	int n;
	while (scanf("%d", &n) == 1 && n) {
		printf("%d : %d\n", n, dp[n]);
	}

	return 0;
}
