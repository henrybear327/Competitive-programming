#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int inp[n];
	for(int i = 0; i < n; i++) 
		scanf("%d", &inp[i]);
	
	// 1 2 1 2
	int lr = inp[0], rl = inp[n - 1];
	for(int i = 1; i < n; i++) {
		if(inp[i] > inp[i - 1])
			continue;
		lr = inp[i - 1];
		break;
	}
	
	for(int i = n - 2; i >= 0; i--) {
		if(inp[i] > inp[i + 1])
			continue;
		rl = inp[i + 1];
		break;
	}
	
	for(int i = lr; i <= rl; i++) {
		if(i + 1 <= rl && inp[i] == inp[i + 1])
			continue;
		printf("NO\n");
		return 0;
	}
	printf("YES\n");

	return 0;
}
