#include <bits/stdc++.h>

using namespace std;

int a, b;
int dp[111][111];

void init() 
{
	for(int i = 0; i < 111; i++)
		for(int j = 0; j < 111; j++) 
			dp[i][j] = i == j ? 0 : 11111;
}

void sp()
{
	for(int k = 0; k < 111; k++)
		for(int i = 0; i < 111; i++)
			for(int j = 0; j < 111; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

int main()
{
	init();
	bool has = false;
	int ncase = 1;
	while(scanf("%d %d", &a, &b) == 2) {
		if(a == 0 && b == 0) {
			if(has == false)
				break;
			// floyd warshall
			sp();
			
			int sum = 0, cnt = 0;
			for(int i = 0; i < 111; i++)
				for(int j = 0; j < 111; j++)
					if(i != j && dp[i][j] != 11111) {
						sum += dp[i][j];
						cnt++;
					}

			printf("Case %d: average length between pages = %.3f clicks\n", ncase++, (double)sum / cnt);

			init();
			has = false;
		} else {
			has = true;
			dp[a][b] = 1;
		}
	}

	return 0;
}
