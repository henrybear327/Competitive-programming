#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ii count(ll num) 
{
	if(num == 0)
		return ii(1, 1);

	ii res = ii(0, 0);
	while(num % 2 == 0) {
		num /= 2;
		res.first++;
	}

	while(num % 5 == 0) {
		num /= 5;
		res.second++;
	}		

	return res;
}

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

	ll inp[n][n];
	int zx = -1, zy = -1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			scanf("%lld", &inp[i][j]);
			if(inp[i][j] == 0) {
				zx = i;
				zy = j;
			}
		}
	
	/*
	if you view (2, 5) together
	wrong answer!
	3
	5 5 1 
	2 1 2 
	1 1 4
	*/
	ii dp[n][n][2];
	int dir[n][n][2];
	// base case
	


	return 0;
}
