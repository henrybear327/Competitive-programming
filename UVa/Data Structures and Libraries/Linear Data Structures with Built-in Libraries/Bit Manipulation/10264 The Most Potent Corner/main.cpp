#include <bits/stdc++.h>

using namespace std;

const int N = ((1 << 15) + 1);
int inp[N];

int main()
{
	int n;
	while(scanf("%d", &n) == 1) {
		int upper = (1 << n);
		for(int i = 0; i < upper; i++) 
			scanf("%d", &inp[i]);
		
		int sum[upper] = {0};
		for(int i = 0; i < upper; i++) {
			for(int j = 0; j < n; j++) {
				sum[i] += inp[i ^ (1 << j)];
			}
		}
		
		int ans = 0;
		for(int i = 0; i < upper; i++) {
			int best = 0;
			for(int j = 0; j < n; j++) 
				best = max(best, sum[i] + sum[i ^ (1 << j)]);
			ans = max(ans, best);
		}

		printf("%d\n", ans);
	}

	return 0;
}
