#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
#define M 100000000

int g[12][12];
int gb[12];
bool check(int r, int x) // no neighbors are selected
{
    int invalid = gb[r];
    if(invalid & x)  {
	// if ok is 110, invalid will be 001
	// if x is 101, 001 & 101 != 0 -> false
	// if x is 100, 001 & 100 = 0 -> ok
	return false;
    }

    // check for cont. 1s
    for(int i = 1; i < 12 && x > 0; i++) {
	if( (x & (1 << i)) && (x & (1 << (i - 1))) )
	    return false;
    }
    return true;
}

int main()
{
    int m, n;
    while(scanf("%d %d", &m, &n) == 2) {
	for(int i = 0; i < m; i++) {
	    // scan input
	    for(int j = 0; j < n; j++)
		scanf("%d", &g[i][j]);
	    // make the row into a number
	    int encode = 0;
	    for(int j = 0; j < n; j++) {
		if(g[i][j] == 0) {
		    encode += (1 << j);
		}
	    }
	    gb[i] = encode;
	}

	const int upperBound = (1 << n);
	ll dp[12][upperBound];
	memset(dp, 0, sizeof(dp));

	// base case
	// if the condition is satisfied, mark as 1
	for(int j = 0; j < upperBound; j++) {
	    if(check(0, j))
		dp[0][j] = 1;
	}

	// build the table up row by row
	// row i + 1 depends only on row i
	for(int i = 1; i < m; i++) {
	    for(int j = 0; j < upperBound; j++) { // i - 1
		for(int k = 0; k < upperBound; k++) { // i
		    if(check(i, k) && (j & k) == 0) {
			dp[i][k] += dp[i - 1][j];
			dp[i][k] %= M;
		    }
		}
	    }
	}

	ll ans = 0;
	for(int i = 0; i < upperBound; i++) {
	    ans += dp[m - 1][i];
	    ans %= M;
	}

	/*
	   for(int i = 0; i < m; i++)
	   for(int j = 0; j < upperBound; j++)
	   printf("%lld%c", dp[i][j], j == upperBound - 1 ? '\n' : ' ');
	 */
	printf("%lld\n", ans);
    }

    return 0;
}
