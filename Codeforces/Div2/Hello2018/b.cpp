#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	int par[n];
	par[0] = -1;
	int in[n];
	memset(in, 0, sizeof(in));
	for(int i = 1; i < n; i++) {
		scanf("%d", &par[i]);
		par[i]--;
		in[par[i]]++;
	}

	int dp[n];
	memset(dp, 0, sizeof(dp));
	for(int i = n - 1; i >= 1; i--) {
		if(in[i] == 0) 
			dp[par[i]]++;
	}
	
	bool ok = true;
	for(int i = 0; i < n; i++) {
		if(in[i] > 0) {
			if(dp[i] < 3)
				ok = false;
		}
	}
	printf("%s\n", ok ? "Yes" : "No");
	
    return 0;
}
