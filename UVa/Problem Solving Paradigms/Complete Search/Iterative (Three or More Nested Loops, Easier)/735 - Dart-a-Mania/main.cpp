#include <bits/stdc++.h>

using namespace std;

int cnt[1000], cnt1[1000];
void solve(int n)
{
	// printf("%d %d\n", cnt[n], cnt1[n]);	
	if(cnt[n] == 0) 
		printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
	else {
		printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, cnt1[n]);
		printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, cnt[n]);
	}
}

int main()
{
	int n;
	
	bool can[200] = {false};
	can[50] = true; // man, 30 minutes wasted
	for(int i = 0; i <= 20; i++)
		for(int j = 1; j <= 3; j++)
			can[i * j] = true;
	
	int base[43], idx = 0;
	for(int i = 0; i < 200; i++)
		if(can[i]) {
			base[idx++] = i;
		}
	
	memset(cnt, 0, sizeof(cnt));
	memset(cnt1, 0, sizeof(cnt1));
	for(int i = 0; i < 43; i++)
		for(int j = 0; j < 43; j++)
			for(int k = 0; k < 43; k++) {
				if(k >= j && j >= i)
					cnt1[base[i] + base[j] + base[k]]++;
				cnt[base[i] + base[j] + base[k]]++;
			}
	
	while(scanf("%d", &n) == 1 && n > 0) {
		solve(n);
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");

	return 0;
}
