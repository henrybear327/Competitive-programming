#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	ll val[n];
	for(int i = 0; i < n; i++)
		scanf("%lld", &val[i]);
	
	ll dp[n][2];
	for(int i = 0; i < n; i++)
		dp[i][0] = dp[i][1] = LLONG_MAX;
	dp[0][0] = 0;
	dp[0][1] = val[0];
	
	char tmp[100100];
	scanf("%s", tmp);

	string str1 = tmp;
	int len = strlen(tmp);
	reverse(tmp, tmp + len);
	string str2 = tmp;

	if(str1 == str2) {
		dp[0][1] = 0;
		val[0] = 0;
	}
	for(int i = 1; i < n; i++) {
		scanf("%s", tmp);
		string str3 = tmp;
		len = strlen(tmp);
		reverse(tmp, tmp + len);
		string str4 = tmp;

		if(str3 ==str4)
			val[i] = 0;
		
		if(str1 <= str3)
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if(str1 <= str4 && dp[i - 1][0] != LLONG_MAX)
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + val[i]);
		if(str2 <= str3) 
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if(str2 <= str4 && dp[i - 1][1] !=LLONG_MAX) 
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + val[i]);

		str1 = str3;
		str2 = str4;
	}
	
	/*
	for(int i = 0; i < n; i++)
		printf("%d %lld %lld\n", i, dp[i][0], dp[i][1]);
	*/

	ll res = min(dp[n - 1][0], dp[n - 1][1]);
	
	if(res == LLONG_MAX) {
		res = -1;
	}

	printf("%lld\n",res);
	
    return 0;
}
