#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

#define MOD 1000000007

int main()
{
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);

    int DP[n + 1][2];
    memset(DP, 0, sizeof(DP));
    DP[0][0] = 1;


    for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= k; j++) {
	    if(j > i) // it's over the sum limit
		break;

	    if(j < d) {
		DP[i][0] = (DP[i][0] + DP[i - j][0]) % MOD;
		DP[i][1] = (DP[i][1] + DP[i - j][1]) % MOD;
	    } else { // j >= d
		DP[i][1] = (DP[i][1] + DP[i - j][0]) % MOD;
		DP[i][1] = (DP[i][1] + DP[i - j][1]) % MOD;
	    }
	}
    }

    printf("%d\n", DP[n][1]);

    return 0;
}
