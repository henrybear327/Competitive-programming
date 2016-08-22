#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	if(n == 1) {
		printf("1\n");
		return 0;
	}

	while(n % 2 == 0); //shouldn't happen

	int ans[n][n];
	memset(ans, 0, sizeof(ans));

	// put odd
	int odd = 1, even = 2, lb, rb, cnt = 1;
	for(int i = 0; i < n; i++) {
		lb = n / 2 - cnt / 2;
		rb = n / 2 + cnt / 2;
		for(int j = 0; j < n; j++) {
			if(lb <= j && j <= rb) {
				ans[i][j] = odd;
				odd += 2;
			} else {
				ans[i][j] = even;
				even += 2;
			}
		}

		if(i < n / 2)
			cnt += 2;
		else
			cnt -= 2;
	}

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			printf("%d%c", ans[i][j], j == n - 1 ? '\n' : ' ');

	return 0;
}
